#include <stdio.h>
#include <sys/time.h>

#include "yukumo_0001.cpp"
#include "adpcm-lib.h"

uint64_t now_usec() {
    struct timeval tmv;
    gettimeofday( &tmv, NULL );
    return (uint64_t)(tmv.tv_sec)*1000000LL  + (uint64_t)(tmv.tv_usec);
}


int main() {
    int inideltas[2]={0,0};
    void *ctx=adpcm_create_context(1,0,0,inideltas);

    uint8_t outbuf[80000];
    size_t outbufsize=sizeof(outbuf);
    uint64_t st=now_usec();
    int n=adpcm_encode_block (ctx,outbuf, &outbufsize, g_samples, sizeof(g_samples)/2);
    uint64_t dt=now_usec()-st;    
    fprintf(stderr,"N:%d sz:%lu dt:%llu\n",n,outbufsize,dt);
    //    int adpcm_decode_block (int16_t *outbuf, const uint8_t *inbuf, size_t inbufsize, int channels);
    
    adpcm_free_context(ctx);
    return 0;
}

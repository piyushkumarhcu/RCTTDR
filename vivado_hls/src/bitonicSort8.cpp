#include "bitonicSort8.h"

//Main CAE block (compare and exchange)
GreaterSmaller AscendDescend( Cluster &x,  Cluster &y){
#pragma HLS PIPELINE II=6
#pragma HLS INLINE
    GreaterSmaller s;

    s.greater = (x.clusterEnergy() > y.clusterEnergy()) ? x : y;
    s.smaller = (x.clusterEnergy() > y.clusterEnergy()) ? y : x;

    return s;
}

void FourinSmallFir( Cluster &x0,  Cluster &x1,  Cluster &x2,  Cluster &x3,
					Cluster &y0, Cluster &y1, Cluster &y2, Cluster &y3){
   #pragma HLS PIPELINE II=6
   #pragma HLS INLINE
    GreaterSmaller res;
        res = AscendDescend(x0, x2);
        y0 = res.smaller; y2 = res.greater;

        res = AscendDescend(x1, x3);
        y1 = res.smaller; y3 = res.greater;
}

void FourinGreatFir( Cluster &x0,  Cluster &x1,  Cluster &x2,  Cluster &x3,
					Cluster &y0, Cluster &y1, Cluster &y2, Cluster &y3){
   #pragma HLS PIPELINE II=6
   #pragma HLS INLINE
    GreaterSmaller res;
        res = AscendDescend(x0, x2);
        y0 = res.greater; y2 = res.smaller;

        res = AscendDescend(x1, x3);
        y1 = res.greater; y3 = res.smaller;
}

void bitonicSort8(Cluster in[Nbclusters], Cluster out[Nbclusters]){
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=in
#pragma HLS ARRAY_PARTITION variable=out

GreaterSmaller result;

Cluster a[Nbclusters], b[Nbclusters], c[Nbclusters], d[Nbclusters], e[Nbclusters];
#pragma HLS ARRAY_PARTITION variable=a
#pragma HLS ARRAY_PARTITION variable=b
#pragma HLS ARRAY_PARTITION variable=c
#pragma HLS ARRAY_PARTITION variable=d
#pragma HLS ARRAY_PARTITION variable=e

//Starting of first stage

for(loop i=0; i<Nbclusters/4; i++){
    #pragma HLS unroll
    result = AscendDescend(in[4*i], in[4*i+1]);
    a[4*i] = result.smaller; a[4*i+1] = result.greater; 
}

for(loop i=0; i<Nbclusters/4; i++){
    #pragma HLS unroll
    result = AscendDescend(in[4*i+2], in[4*i+3]);
    a[4*i+2] = result.greater; a[4*i+3] = result.smaller; 
}

//Starting of second stage

    FourinSmallFir(a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]);
    FourinGreatFir(a[4], a[5], a[6], a[7], b[4], b[5], b[6], b[7]); 

//Starting of third stage

    result = AscendDescend(b[0], b[1]);
    c[0] = result.smaller; c[1] = result.greater; 
 
    result = AscendDescend(b[2], b[3]);
    c[2] = result.smaller; c[3] = result.greater;

    result = AscendDescend(b[4], b[5]);
    c[4] = result.greater; c[5] = result.smaller; 

    result = AscendDescend(b[6], b[7]);
    c[6] = result.greater; c[7] = result.smaller;

//Starting of fourth stage

for(loop i=0; i<Nbclusters/2; i++){
    #pragma HLS unroll
    result = AscendDescend(c[i], c[i+4]);
    d[i] = result.smaller; d[i+4] = result.greater;
}

//starting fifth stage

    FourinSmallFir(d[0], d[1], d[2], d[3], e[0], e[1], e[2], e[3]);
    FourinSmallFir(d[4], d[5], d[6], d[7], e[4], e[5], e[6], e[7]);

//starting sixth stage

for(loop i=0; i<Nbclusters/2; i++){
    #pragma HLS unroll
    result = AscendDescend(e[2*i], e[2*i+1]);
    out[2*i] = result.smaller; out[2*i+1] = result.greater;
}

}




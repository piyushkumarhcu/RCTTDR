#ifndef _BITONICSORT8_H_
#define _BITONICSORT8_H_

#include <iostream>
#include "ap_int.h"
#include "algo_top.h"
#include "algo_top_parameters.h"
#define Nbclusters 8

using namespace std;

class GreaterSmaller{
public:
    Cluster greater, smaller;
};

void bitonicSort8(Cluster in[Nbclusters], Cluster out[Nbclusters]);

#endif



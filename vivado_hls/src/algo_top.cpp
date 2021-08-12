#include "algo_top.h"
#include "algo_top_parameters.h"
#include "bitonicSort8.h"

void processInputLinks(ap_uint<384> link_in[N_INPUT_LINKS], crystal ECALRegion3x4_1[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI], crystal ECALRegion3x4_2[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI], towerHCAL HCALRegion4x4_1[HCAL_TOWER_IN_ETA][HCAL_TOWER_IN_PHI], towerHCAL HCALRegion4x4_2[HCAL_TOWER_IN_ETA][HCAL_TOWER_IN_PHI]){
	    #pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
        #pragma HLS ARRAY_PARTITION variable=ECALRegion3x4_1 complete dim=0
        #pragma HLS ARRAY_PARTITION variable=ECALRegion3x4_2 complete dim=0
        #pragma HLS ARRAY_PARTITION variable=HCALRegion4x4_1 complete dim=0
        #pragma HLS ARRAY_PARTITION variable=HCALRegion4x4_2 complete dim=0

        ap_uint<32> start = 0;
        ap_uint<32> end = 13;
  
        ap_uint<6> wordId, wordId1, startId ;


        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
                #pragma HLS UNROLL
                for(loop j=0; j<CRYSTAL_IN_PHI; j++){
                        #pragma HLS UNROLL
                       wordId = (i/5)*4+(j/5) ;
                       wordId1 = wordId + 12 ;
                       startId = (i%5)*5+(j%5) ;
                       start = startId*14 ; end = start + 13 ;

                       ECALRegion3x4_1[i][j] = crystal(link_in[wordId].range(end, start));
                       ECALRegion3x4_2[i][j] = crystal(link_in[wordId1].range(end, start));
 
         }}


        start = 0; end = 15;
        for(loop i=0; i<HCAL_TOWER_IN_ETA; i++){
            //#pragma HLS UNROLL
            for(loop j=0; j<HCAL_TOWER_IN_PHI; j++){
                #pragma HLS UNROLL
                    HCALRegion4x4_1[i][j] = towerHCAL(link_in[24].range(end, start));
                    HCALRegion4x4_2[i][j] = towerHCAL(link_in[25].range(end, start));
                    start += 16; end += 16;
            }
        }
}

ecalRegion_t initStructure(crystal temporary[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI]){

#pragma HLS ARRAY_PARTITION variable=temporary complete dim=0
//#pragma HLS PIPELINE II=6
//#pragma HLS INLINE off

ap_uint<5> Phi = 0 ;
ap_uint<5> Eta = 0 ;

ecalRegion_t out;

out.etaStrip0.cr0.energy=temporary[Eta+0][Phi+0].energy; out.etaStrip0.cr0.eta=0; out.etaStrip0.cr0.phi=0;
out.etaStrip0.cr1.energy=temporary[Eta+0][Phi+1].energy; out.etaStrip0.cr1.eta=0; out.etaStrip0.cr1.phi=1;
out.etaStrip0.cr2.energy=temporary[Eta+0][Phi+2].energy; out.etaStrip0.cr2.eta=0; out.etaStrip0.cr2.phi=2;
out.etaStrip0.cr3.energy=temporary[Eta+0][Phi+3].energy; out.etaStrip0.cr3.eta=0; out.etaStrip0.cr3.phi=3;
out.etaStrip0.cr4.energy=temporary[Eta+0][Phi+4].energy; out.etaStrip0.cr4.eta=0; out.etaStrip0.cr4.phi=4;
out.etaStrip0.cr5.energy=temporary[Eta+0][Phi+5].energy; out.etaStrip0.cr5.eta=0; out.etaStrip0.cr5.phi=5;
out.etaStrip0.cr6.energy=temporary[Eta+0][Phi+6].energy; out.etaStrip0.cr6.eta=0; out.etaStrip0.cr6.phi=6;
out.etaStrip0.cr7.energy=temporary[Eta+0][Phi+7].energy; out.etaStrip0.cr7.eta=0; out.etaStrip0.cr7.phi=7;
out.etaStrip0.cr8.energy=temporary[Eta+0][Phi+8].energy; out.etaStrip0.cr8.eta=0; out.etaStrip0.cr8.phi=8;
out.etaStrip0.cr9.energy=temporary[Eta+0][Phi+9].energy; out.etaStrip0.cr9.eta=0; out.etaStrip0.cr9.phi=9;
out.etaStrip0.cr10.energy=temporary[Eta+0][Phi+10].energy; out.etaStrip0.cr10.eta=0; out.etaStrip0.cr10.phi=10;
out.etaStrip0.cr11.energy=temporary[Eta+0][Phi+11].energy; out.etaStrip0.cr11.eta=0; out.etaStrip0.cr11.phi=11;
out.etaStrip0.cr12.energy=temporary[Eta+0][Phi+12].energy; out.etaStrip0.cr12.eta=0; out.etaStrip0.cr12.phi=12;
out.etaStrip0.cr13.energy=temporary[Eta+0][Phi+13].energy; out.etaStrip0.cr13.eta=0; out.etaStrip0.cr13.phi=13;
out.etaStrip0.cr14.energy=temporary[Eta+0][Phi+14].energy; out.etaStrip0.cr14.eta=0; out.etaStrip0.cr14.phi=14;
out.etaStrip0.cr15.energy=temporary[Eta+0][Phi+15].energy; out.etaStrip0.cr15.eta=0; out.etaStrip0.cr15.phi=15;
out.etaStrip0.cr16.energy=temporary[Eta+0][Phi+16].energy; out.etaStrip0.cr16.eta=0; out.etaStrip0.cr16.phi=16;
out.etaStrip0.cr17.energy=temporary[Eta+0][Phi+17].energy; out.etaStrip0.cr17.eta=0; out.etaStrip0.cr17.phi=17;
out.etaStrip0.cr18.energy=temporary[Eta+0][Phi+18].energy; out.etaStrip0.cr18.eta=0; out.etaStrip0.cr18.phi=18;
out.etaStrip0.cr19.energy=temporary[Eta+0][Phi+19].energy; out.etaStrip0.cr19.eta=0; out.etaStrip0.cr19.phi=19;

out.etaStrip1.cr0.energy=temporary[Eta+1][Phi+0].energy; out.etaStrip1.cr0.eta=1; out.etaStrip1.cr0.phi=0;
out.etaStrip1.cr1.energy=temporary[Eta+1][Phi+1].energy; out.etaStrip1.cr1.eta=1; out.etaStrip1.cr1.phi=1;
out.etaStrip1.cr2.energy=temporary[Eta+1][Phi+2].energy; out.etaStrip1.cr2.eta=1; out.etaStrip1.cr2.phi=2;
out.etaStrip1.cr3.energy=temporary[Eta+1][Phi+3].energy; out.etaStrip1.cr3.eta=1; out.etaStrip1.cr3.phi=3;
out.etaStrip1.cr4.energy=temporary[Eta+1][Phi+4].energy; out.etaStrip1.cr4.eta=1; out.etaStrip1.cr4.phi=4;
out.etaStrip1.cr5.energy=temporary[Eta+1][Phi+5].energy; out.etaStrip1.cr5.eta=1; out.etaStrip1.cr5.phi=5;
out.etaStrip1.cr6.energy=temporary[Eta+1][Phi+6].energy; out.etaStrip1.cr6.eta=1; out.etaStrip1.cr6.phi=6;
out.etaStrip1.cr7.energy=temporary[Eta+1][Phi+7].energy; out.etaStrip1.cr7.eta=1; out.etaStrip1.cr7.phi=7;
out.etaStrip1.cr8.energy=temporary[Eta+1][Phi+8].energy; out.etaStrip1.cr8.eta=1; out.etaStrip1.cr8.phi=8;
out.etaStrip1.cr9.energy=temporary[Eta+1][Phi+9].energy; out.etaStrip1.cr9.eta=1; out.etaStrip1.cr9.phi=9;
out.etaStrip1.cr10.energy=temporary[Eta+1][Phi+10].energy; out.etaStrip1.cr10.eta=1; out.etaStrip1.cr10.phi=10;
out.etaStrip1.cr11.energy=temporary[Eta+1][Phi+11].energy; out.etaStrip1.cr11.eta=1; out.etaStrip1.cr11.phi=11;
out.etaStrip1.cr12.energy=temporary[Eta+1][Phi+12].energy; out.etaStrip1.cr12.eta=1; out.etaStrip1.cr12.phi=12;
out.etaStrip1.cr13.energy=temporary[Eta+1][Phi+13].energy; out.etaStrip1.cr13.eta=1; out.etaStrip1.cr13.phi=13;
out.etaStrip1.cr14.energy=temporary[Eta+1][Phi+14].energy; out.etaStrip1.cr14.eta=1; out.etaStrip1.cr14.phi=14;
out.etaStrip1.cr15.energy=temporary[Eta+1][Phi+15].energy; out.etaStrip1.cr15.eta=1; out.etaStrip1.cr15.phi=15;
out.etaStrip1.cr16.energy=temporary[Eta+1][Phi+16].energy; out.etaStrip1.cr16.eta=1; out.etaStrip1.cr16.phi=16;
out.etaStrip1.cr17.energy=temporary[Eta+1][Phi+17].energy; out.etaStrip1.cr17.eta=1; out.etaStrip1.cr17.phi=17;
out.etaStrip1.cr18.energy=temporary[Eta+1][Phi+18].energy; out.etaStrip1.cr18.eta=1; out.etaStrip1.cr18.phi=18;
out.etaStrip1.cr19.energy=temporary[Eta+1][Phi+19].energy; out.etaStrip1.cr19.eta=1; out.etaStrip1.cr19.phi=19;

out.etaStrip2.cr0.energy=temporary[Eta+2][Phi+0].energy; out.etaStrip2.cr0.eta=2; out.etaStrip2.cr0.phi=0;
out.etaStrip2.cr1.energy=temporary[Eta+2][Phi+1].energy; out.etaStrip2.cr1.eta=2; out.etaStrip2.cr1.phi=1;
out.etaStrip2.cr2.energy=temporary[Eta+2][Phi+2].energy; out.etaStrip2.cr2.eta=2; out.etaStrip2.cr2.phi=2;
out.etaStrip2.cr3.energy=temporary[Eta+2][Phi+3].energy; out.etaStrip2.cr3.eta=2; out.etaStrip2.cr3.phi=3;
out.etaStrip2.cr4.energy=temporary[Eta+2][Phi+4].energy; out.etaStrip2.cr4.eta=2; out.etaStrip2.cr4.phi=4;
out.etaStrip2.cr5.energy=temporary[Eta+2][Phi+5].energy; out.etaStrip2.cr5.eta=2; out.etaStrip2.cr5.phi=5;
out.etaStrip2.cr6.energy=temporary[Eta+2][Phi+6].energy; out.etaStrip2.cr6.eta=2; out.etaStrip2.cr6.phi=6;
out.etaStrip2.cr7.energy=temporary[Eta+2][Phi+7].energy; out.etaStrip2.cr7.eta=2; out.etaStrip2.cr7.phi=7;
out.etaStrip2.cr8.energy=temporary[Eta+2][Phi+8].energy; out.etaStrip2.cr8.eta=2; out.etaStrip2.cr8.phi=8;
out.etaStrip2.cr9.energy=temporary[Eta+2][Phi+9].energy; out.etaStrip2.cr9.eta=2; out.etaStrip2.cr9.phi=9;
out.etaStrip2.cr10.energy=temporary[Eta+2][Phi+10].energy; out.etaStrip2.cr10.eta=2; out.etaStrip2.cr10.phi=10;
out.etaStrip2.cr11.energy=temporary[Eta+2][Phi+11].energy; out.etaStrip2.cr11.eta=2; out.etaStrip2.cr11.phi=11;
out.etaStrip2.cr12.energy=temporary[Eta+2][Phi+12].energy; out.etaStrip2.cr12.eta=2; out.etaStrip2.cr12.phi=12;
out.etaStrip2.cr13.energy=temporary[Eta+2][Phi+13].energy; out.etaStrip2.cr13.eta=2; out.etaStrip2.cr13.phi=13;
out.etaStrip2.cr14.energy=temporary[Eta+2][Phi+14].energy; out.etaStrip2.cr14.eta=2; out.etaStrip2.cr14.phi=14;
out.etaStrip2.cr15.energy=temporary[Eta+2][Phi+15].energy; out.etaStrip2.cr15.eta=2; out.etaStrip2.cr15.phi=15;
out.etaStrip2.cr16.energy=temporary[Eta+2][Phi+16].energy; out.etaStrip2.cr16.eta=2; out.etaStrip2.cr16.phi=16;
out.etaStrip2.cr17.energy=temporary[Eta+2][Phi+17].energy; out.etaStrip2.cr17.eta=2; out.etaStrip2.cr17.phi=17;
out.etaStrip2.cr18.energy=temporary[Eta+2][Phi+18].energy; out.etaStrip2.cr18.eta=2; out.etaStrip2.cr18.phi=18;
out.etaStrip2.cr19.energy=temporary[Eta+2][Phi+19].energy; out.etaStrip2.cr19.eta=2; out.etaStrip2.cr19.phi=19;

out.etaStrip3.cr0.energy=temporary[Eta+3][Phi+0].energy; out.etaStrip3.cr0.eta=3; out.etaStrip3.cr0.phi=0;
out.etaStrip3.cr1.energy=temporary[Eta+3][Phi+1].energy; out.etaStrip3.cr1.eta=3; out.etaStrip3.cr1.phi=1;
out.etaStrip3.cr2.energy=temporary[Eta+3][Phi+2].energy; out.etaStrip3.cr2.eta=3; out.etaStrip3.cr2.phi=2;
out.etaStrip3.cr3.energy=temporary[Eta+3][Phi+3].energy; out.etaStrip3.cr3.eta=3; out.etaStrip3.cr3.phi=3;
out.etaStrip3.cr4.energy=temporary[Eta+3][Phi+4].energy; out.etaStrip3.cr4.eta=3; out.etaStrip3.cr4.phi=4;
out.etaStrip3.cr5.energy=temporary[Eta+3][Phi+5].energy; out.etaStrip3.cr5.eta=3; out.etaStrip3.cr5.phi=5;
out.etaStrip3.cr6.energy=temporary[Eta+3][Phi+6].energy; out.etaStrip3.cr6.eta=3; out.etaStrip3.cr6.phi=6;
out.etaStrip3.cr7.energy=temporary[Eta+3][Phi+7].energy; out.etaStrip3.cr7.eta=3; out.etaStrip3.cr7.phi=7;
out.etaStrip3.cr8.energy=temporary[Eta+3][Phi+8].energy; out.etaStrip3.cr8.eta=3; out.etaStrip3.cr8.phi=8;
out.etaStrip3.cr9.energy=temporary[Eta+3][Phi+9].energy; out.etaStrip3.cr9.eta=3; out.etaStrip3.cr9.phi=9;
out.etaStrip3.cr10.energy=temporary[Eta+3][Phi+10].energy; out.etaStrip3.cr10.eta=3; out.etaStrip3.cr10.phi=10;
out.etaStrip3.cr11.energy=temporary[Eta+3][Phi+11].energy; out.etaStrip3.cr11.eta=3; out.etaStrip3.cr11.phi=11;
out.etaStrip3.cr12.energy=temporary[Eta+3][Phi+12].energy; out.etaStrip3.cr12.eta=3; out.etaStrip3.cr12.phi=12;
out.etaStrip3.cr13.energy=temporary[Eta+3][Phi+13].energy; out.etaStrip3.cr13.eta=3; out.etaStrip3.cr13.phi=13;
out.etaStrip3.cr14.energy=temporary[Eta+3][Phi+14].energy; out.etaStrip3.cr14.eta=3; out.etaStrip3.cr14.phi=14;
out.etaStrip3.cr15.energy=temporary[Eta+3][Phi+15].energy; out.etaStrip3.cr15.eta=3; out.etaStrip3.cr15.phi=15;
out.etaStrip3.cr16.energy=temporary[Eta+3][Phi+16].energy; out.etaStrip3.cr16.eta=3; out.etaStrip3.cr16.phi=16;
out.etaStrip3.cr17.energy=temporary[Eta+3][Phi+17].energy; out.etaStrip3.cr17.eta=3; out.etaStrip3.cr17.phi=17;
out.etaStrip3.cr18.energy=temporary[Eta+3][Phi+18].energy; out.etaStrip3.cr18.eta=3; out.etaStrip3.cr18.phi=18;
out.etaStrip3.cr19.energy=temporary[Eta+3][Phi+19].energy; out.etaStrip3.cr19.eta=3; out.etaStrip3.cr19.phi=19;

out.etaStrip4.cr0.energy=temporary[Eta+4][Phi+0].energy; out.etaStrip4.cr0.eta=4; out.etaStrip4.cr0.phi=0;
out.etaStrip4.cr1.energy=temporary[Eta+4][Phi+1].energy; out.etaStrip4.cr1.eta=4; out.etaStrip4.cr1.phi=1;
out.etaStrip4.cr2.energy=temporary[Eta+4][Phi+2].energy; out.etaStrip4.cr2.eta=4; out.etaStrip4.cr2.phi=2;
out.etaStrip4.cr3.energy=temporary[Eta+4][Phi+3].energy; out.etaStrip4.cr3.eta=4; out.etaStrip4.cr3.phi=3;
out.etaStrip4.cr4.energy=temporary[Eta+4][Phi+4].energy; out.etaStrip4.cr4.eta=4; out.etaStrip4.cr4.phi=4;
out.etaStrip4.cr5.energy=temporary[Eta+4][Phi+5].energy; out.etaStrip4.cr5.eta=4; out.etaStrip4.cr5.phi=5;
out.etaStrip4.cr6.energy=temporary[Eta+4][Phi+6].energy; out.etaStrip4.cr6.eta=4; out.etaStrip4.cr6.phi=6;
out.etaStrip4.cr7.energy=temporary[Eta+4][Phi+7].energy; out.etaStrip4.cr7.eta=4; out.etaStrip4.cr7.phi=7;
out.etaStrip4.cr8.energy=temporary[Eta+4][Phi+8].energy; out.etaStrip4.cr8.eta=4; out.etaStrip4.cr8.phi=8;
out.etaStrip4.cr9.energy=temporary[Eta+4][Phi+9].energy; out.etaStrip4.cr9.eta=4; out.etaStrip4.cr9.phi=9;
out.etaStrip4.cr10.energy=temporary[Eta+4][Phi+10].energy; out.etaStrip4.cr10.eta=4; out.etaStrip4.cr10.phi=10;
out.etaStrip4.cr11.energy=temporary[Eta+4][Phi+11].energy; out.etaStrip4.cr11.eta=4; out.etaStrip4.cr11.phi=11;
out.etaStrip4.cr12.energy=temporary[Eta+4][Phi+12].energy; out.etaStrip4.cr12.eta=4; out.etaStrip4.cr12.phi=12;
out.etaStrip4.cr13.energy=temporary[Eta+4][Phi+13].energy; out.etaStrip4.cr13.eta=4; out.etaStrip4.cr13.phi=13;
out.etaStrip4.cr14.energy=temporary[Eta+4][Phi+14].energy; out.etaStrip4.cr14.eta=4; out.etaStrip4.cr14.phi=14;
out.etaStrip4.cr15.energy=temporary[Eta+4][Phi+15].energy; out.etaStrip4.cr15.eta=4; out.etaStrip4.cr15.phi=15;
out.etaStrip4.cr16.energy=temporary[Eta+4][Phi+16].energy; out.etaStrip4.cr16.eta=4; out.etaStrip4.cr16.phi=16;
out.etaStrip4.cr17.energy=temporary[Eta+4][Phi+17].energy; out.etaStrip4.cr17.eta=4; out.etaStrip4.cr17.phi=17;
out.etaStrip4.cr18.energy=temporary[Eta+4][Phi+18].energy; out.etaStrip4.cr18.eta=4; out.etaStrip4.cr18.phi=18;
out.etaStrip4.cr19.energy=temporary[Eta+4][Phi+19].energy; out.etaStrip4.cr19.eta=4; out.etaStrip4.cr19.phi=19;

out.etaStrip5.cr0.energy=temporary[Eta+5][Phi+0].energy; out.etaStrip5.cr0.eta=5; out.etaStrip5.cr0.phi=0;
out.etaStrip5.cr1.energy=temporary[Eta+5][Phi+1].energy; out.etaStrip5.cr1.eta=5; out.etaStrip5.cr1.phi=1;
out.etaStrip5.cr2.energy=temporary[Eta+5][Phi+2].energy; out.etaStrip5.cr2.eta=5; out.etaStrip5.cr2.phi=2;
out.etaStrip5.cr3.energy=temporary[Eta+5][Phi+3].energy; out.etaStrip5.cr3.eta=5; out.etaStrip5.cr3.phi=3;
out.etaStrip5.cr4.energy=temporary[Eta+5][Phi+4].energy; out.etaStrip5.cr4.eta=5; out.etaStrip5.cr4.phi=4;
out.etaStrip5.cr5.energy=temporary[Eta+5][Phi+5].energy; out.etaStrip5.cr5.eta=5; out.etaStrip5.cr5.phi=5;
out.etaStrip5.cr6.energy=temporary[Eta+5][Phi+6].energy; out.etaStrip5.cr6.eta=5; out.etaStrip5.cr6.phi=6;
out.etaStrip5.cr7.energy=temporary[Eta+5][Phi+7].energy; out.etaStrip5.cr7.eta=5; out.etaStrip5.cr7.phi=7;
out.etaStrip5.cr8.energy=temporary[Eta+5][Phi+8].energy; out.etaStrip5.cr8.eta=5; out.etaStrip5.cr8.phi=8;
out.etaStrip5.cr9.energy=temporary[Eta+5][Phi+9].energy; out.etaStrip5.cr9.eta=5; out.etaStrip5.cr9.phi=9;
out.etaStrip5.cr10.energy=temporary[Eta+5][Phi+10].energy; out.etaStrip5.cr10.eta=5; out.etaStrip5.cr10.phi=10;
out.etaStrip5.cr11.energy=temporary[Eta+5][Phi+11].energy; out.etaStrip5.cr11.eta=5; out.etaStrip5.cr11.phi=11;
out.etaStrip5.cr12.energy=temporary[Eta+5][Phi+12].energy; out.etaStrip5.cr12.eta=5; out.etaStrip5.cr12.phi=12;
out.etaStrip5.cr13.energy=temporary[Eta+5][Phi+13].energy; out.etaStrip5.cr13.eta=5; out.etaStrip5.cr13.phi=13;
out.etaStrip5.cr14.energy=temporary[Eta+5][Phi+14].energy; out.etaStrip5.cr14.eta=5; out.etaStrip5.cr14.phi=14;
out.etaStrip5.cr15.energy=temporary[Eta+5][Phi+15].energy; out.etaStrip5.cr15.eta=5; out.etaStrip5.cr15.phi=15;
out.etaStrip5.cr16.energy=temporary[Eta+5][Phi+16].energy; out.etaStrip5.cr16.eta=5; out.etaStrip5.cr16.phi=16;
out.etaStrip5.cr17.energy=temporary[Eta+5][Phi+17].energy; out.etaStrip5.cr17.eta=5; out.etaStrip5.cr17.phi=17;
out.etaStrip5.cr18.energy=temporary[Eta+5][Phi+18].energy; out.etaStrip5.cr18.eta=5; out.etaStrip5.cr18.phi=18;
out.etaStrip5.cr19.energy=temporary[Eta+5][Phi+19].energy; out.etaStrip5.cr19.eta=5; out.etaStrip5.cr19.phi=19;

out.etaStrip6.cr0.energy=temporary[Eta+6][Phi+0].energy; out.etaStrip6.cr0.eta=6; out.etaStrip6.cr0.phi=0;
out.etaStrip6.cr1.energy=temporary[Eta+6][Phi+1].energy; out.etaStrip6.cr1.eta=6; out.etaStrip6.cr1.phi=1;
out.etaStrip6.cr2.energy=temporary[Eta+6][Phi+2].energy; out.etaStrip6.cr2.eta=6; out.etaStrip6.cr2.phi=2;
out.etaStrip6.cr2.energy=temporary[Eta+6][Phi+2].energy; out.etaStrip6.cr2.eta=6; out.etaStrip6.cr2.phi=2;
out.etaStrip6.cr3.energy=temporary[Eta+6][Phi+3].energy; out.etaStrip6.cr3.eta=6; out.etaStrip6.cr3.phi=3;
out.etaStrip6.cr4.energy=temporary[Eta+6][Phi+4].energy; out.etaStrip6.cr4.eta=6; out.etaStrip6.cr4.phi=4;
out.etaStrip6.cr5.energy=temporary[Eta+6][Phi+5].energy; out.etaStrip6.cr5.eta=6; out.etaStrip6.cr5.phi=5;
out.etaStrip6.cr6.energy=temporary[Eta+6][Phi+6].energy; out.etaStrip6.cr6.eta=6; out.etaStrip6.cr6.phi=6;
out.etaStrip6.cr7.energy=temporary[Eta+6][Phi+7].energy; out.etaStrip6.cr7.eta=6; out.etaStrip6.cr7.phi=7;
out.etaStrip6.cr8.energy=temporary[Eta+6][Phi+8].energy; out.etaStrip6.cr8.eta=6; out.etaStrip6.cr8.phi=8;
out.etaStrip6.cr9.energy=temporary[Eta+6][Phi+9].energy; out.etaStrip6.cr9.eta=6; out.etaStrip6.cr9.phi=9;
out.etaStrip6.cr10.energy=temporary[Eta+6][Phi+10].energy; out.etaStrip6.cr10.eta=6; out.etaStrip6.cr10.phi=10;
out.etaStrip6.cr11.energy=temporary[Eta+6][Phi+11].energy; out.etaStrip6.cr11.eta=6; out.etaStrip6.cr11.phi=11;
out.etaStrip6.cr12.energy=temporary[Eta+6][Phi+12].energy; out.etaStrip6.cr12.eta=6; out.etaStrip6.cr12.phi=12;
out.etaStrip6.cr13.energy=temporary[Eta+6][Phi+13].energy; out.etaStrip6.cr13.eta=6; out.etaStrip6.cr13.phi=13;
out.etaStrip6.cr14.energy=temporary[Eta+6][Phi+14].energy; out.etaStrip6.cr14.eta=6; out.etaStrip6.cr14.phi=14;
out.etaStrip6.cr15.energy=temporary[Eta+6][Phi+15].energy; out.etaStrip6.cr15.eta=6; out.etaStrip6.cr15.phi=15;
out.etaStrip6.cr16.energy=temporary[Eta+6][Phi+16].energy; out.etaStrip6.cr16.eta=6; out.etaStrip6.cr16.phi=16;
out.etaStrip6.cr17.energy=temporary[Eta+6][Phi+17].energy; out.etaStrip6.cr17.eta=6; out.etaStrip6.cr17.phi=17;
out.etaStrip6.cr18.energy=temporary[Eta+6][Phi+18].energy; out.etaStrip6.cr18.eta=6; out.etaStrip6.cr18.phi=18;
out.etaStrip6.cr19.energy=temporary[Eta+6][Phi+19].energy; out.etaStrip6.cr19.eta=6; out.etaStrip6.cr19.phi=19;

out.etaStrip7.cr0.energy=temporary[Eta+7][Phi+0].energy; out.etaStrip7.cr0.eta=7; out.etaStrip7.cr0.phi=0;
out.etaStrip7.cr1.energy=temporary[Eta+7][Phi+1].energy; out.etaStrip7.cr1.eta=7; out.etaStrip7.cr1.phi=1;
out.etaStrip7.cr2.energy=temporary[Eta+7][Phi+2].energy; out.etaStrip7.cr2.eta=7; out.etaStrip7.cr2.phi=2;
out.etaStrip7.cr3.energy=temporary[Eta+7][Phi+3].energy; out.etaStrip7.cr3.eta=7; out.etaStrip7.cr3.phi=3;
out.etaStrip7.cr4.energy=temporary[Eta+7][Phi+4].energy; out.etaStrip7.cr4.eta=7; out.etaStrip7.cr4.phi=4;
out.etaStrip7.cr5.energy=temporary[Eta+7][Phi+5].energy; out.etaStrip7.cr5.eta=7; out.etaStrip7.cr5.phi=5;
out.etaStrip7.cr6.energy=temporary[Eta+7][Phi+6].energy; out.etaStrip7.cr6.eta=7; out.etaStrip7.cr6.phi=6;
out.etaStrip7.cr7.energy=temporary[Eta+7][Phi+7].energy; out.etaStrip7.cr7.eta=7; out.etaStrip7.cr7.phi=7;
out.etaStrip7.cr8.energy=temporary[Eta+7][Phi+8].energy; out.etaStrip7.cr8.eta=7; out.etaStrip7.cr8.phi=8;
out.etaStrip7.cr9.energy=temporary[Eta+7][Phi+9].energy; out.etaStrip7.cr9.eta=7; out.etaStrip7.cr9.phi=9;
out.etaStrip7.cr10.energy=temporary[Eta+7][Phi+10].energy; out.etaStrip7.cr10.eta=7; out.etaStrip7.cr10.phi=10;
out.etaStrip7.cr11.energy=temporary[Eta+7][Phi+11].energy; out.etaStrip7.cr11.eta=7; out.etaStrip7.cr11.phi=11;
out.etaStrip7.cr12.energy=temporary[Eta+7][Phi+12].energy; out.etaStrip7.cr12.eta=7; out.etaStrip7.cr12.phi=12;
out.etaStrip7.cr13.energy=temporary[Eta+7][Phi+13].energy; out.etaStrip7.cr13.eta=7; out.etaStrip7.cr13.phi=13;
out.etaStrip7.cr14.energy=temporary[Eta+7][Phi+14].energy; out.etaStrip7.cr14.eta=7; out.etaStrip7.cr14.phi=14;
out.etaStrip7.cr15.energy=temporary[Eta+7][Phi+15].energy; out.etaStrip7.cr15.eta=7; out.etaStrip7.cr15.phi=15;
out.etaStrip7.cr16.energy=temporary[Eta+7][Phi+16].energy; out.etaStrip7.cr16.eta=7; out.etaStrip7.cr16.phi=16;
out.etaStrip7.cr17.energy=temporary[Eta+7][Phi+17].energy; out.etaStrip7.cr17.eta=7; out.etaStrip7.cr17.phi=17;
out.etaStrip7.cr18.energy=temporary[Eta+7][Phi+18].energy; out.etaStrip7.cr18.eta=7; out.etaStrip7.cr18.phi=18;
out.etaStrip7.cr19.energy=temporary[Eta+7][Phi+19].energy; out.etaStrip7.cr19.eta=7; out.etaStrip7.cr19.phi=19;

out.etaStrip8.cr0.energy=temporary[Eta+8][Phi+0].energy; out.etaStrip8.cr0.eta=8; out.etaStrip8.cr0.phi=0;
out.etaStrip8.cr1.energy=temporary[Eta+8][Phi+1].energy; out.etaStrip8.cr1.eta=8; out.etaStrip8.cr1.phi=1;
out.etaStrip8.cr2.energy=temporary[Eta+8][Phi+2].energy; out.etaStrip8.cr2.eta=8; out.etaStrip8.cr2.phi=2;
out.etaStrip8.cr3.energy=temporary[Eta+8][Phi+3].energy; out.etaStrip8.cr3.eta=8; out.etaStrip8.cr3.phi=3;
out.etaStrip8.cr4.energy=temporary[Eta+8][Phi+4].energy; out.etaStrip8.cr4.eta=8; out.etaStrip8.cr4.phi=4;
out.etaStrip8.cr5.energy=temporary[Eta+8][Phi+5].energy; out.etaStrip8.cr5.eta=8; out.etaStrip8.cr5.phi=5;
out.etaStrip8.cr6.energy=temporary[Eta+8][Phi+6].energy; out.etaStrip8.cr6.eta=8; out.etaStrip8.cr6.phi=6;
out.etaStrip8.cr7.energy=temporary[Eta+8][Phi+7].energy; out.etaStrip8.cr7.eta=8; out.etaStrip8.cr7.phi=7;
out.etaStrip8.cr8.energy=temporary[Eta+8][Phi+8].energy; out.etaStrip8.cr8.eta=8; out.etaStrip8.cr8.phi=8;
out.etaStrip8.cr9.energy=temporary[Eta+8][Phi+9].energy; out.etaStrip8.cr9.eta=8; out.etaStrip8.cr9.phi=9;
out.etaStrip8.cr10.energy=temporary[Eta+8][Phi+10].energy; out.etaStrip8.cr10.eta=8; out.etaStrip8.cr10.phi=10;
out.etaStrip8.cr11.energy=temporary[Eta+8][Phi+11].energy; out.etaStrip8.cr11.eta=8; out.etaStrip8.cr11.phi=11;
out.etaStrip8.cr12.energy=temporary[Eta+8][Phi+12].energy; out.etaStrip8.cr12.eta=8; out.etaStrip8.cr12.phi=12;
out.etaStrip8.cr13.energy=temporary[Eta+8][Phi+13].energy; out.etaStrip8.cr13.eta=8; out.etaStrip8.cr13.phi=13;
out.etaStrip8.cr14.energy=temporary[Eta+8][Phi+14].energy; out.etaStrip8.cr14.eta=8; out.etaStrip8.cr14.phi=14;
out.etaStrip8.cr15.energy=temporary[Eta+8][Phi+15].energy; out.etaStrip8.cr15.eta=8; out.etaStrip8.cr15.phi=15;
out.etaStrip8.cr16.energy=temporary[Eta+8][Phi+16].energy; out.etaStrip8.cr16.eta=8; out.etaStrip8.cr16.phi=16;
out.etaStrip8.cr17.energy=temporary[Eta+8][Phi+17].energy; out.etaStrip8.cr17.eta=8; out.etaStrip8.cr17.phi=17;
out.etaStrip8.cr18.energy=temporary[Eta+8][Phi+18].energy; out.etaStrip8.cr18.eta=8; out.etaStrip8.cr18.phi=18;
out.etaStrip8.cr19.energy=temporary[Eta+8][Phi+19].energy; out.etaStrip8.cr19.eta=8; out.etaStrip8.cr19.phi=19;

out.etaStrip9.cr0.energy=temporary[Eta+9][Phi+0].energy; out.etaStrip9.cr0.eta=9; out.etaStrip9.cr0.phi=0;
out.etaStrip9.cr1.energy=temporary[Eta+9][Phi+1].energy; out.etaStrip9.cr1.eta=9; out.etaStrip9.cr1.phi=1;
out.etaStrip9.cr2.energy=temporary[Eta+9][Phi+2].energy; out.etaStrip9.cr2.eta=9; out.etaStrip9.cr2.phi=2;
out.etaStrip9.cr3.energy=temporary[Eta+9][Phi+3].energy; out.etaStrip9.cr3.eta=9; out.etaStrip9.cr3.phi=3;
out.etaStrip9.cr4.energy=temporary[Eta+9][Phi+4].energy; out.etaStrip9.cr4.eta=9; out.etaStrip9.cr4.phi=4;
out.etaStrip9.cr5.energy=temporary[Eta+9][Phi+5].energy; out.etaStrip9.cr5.eta=9; out.etaStrip9.cr5.phi=5;
out.etaStrip9.cr6.energy=temporary[Eta+9][Phi+6].energy; out.etaStrip9.cr6.eta=9; out.etaStrip9.cr6.phi=6;
out.etaStrip9.cr7.energy=temporary[Eta+9][Phi+7].energy; out.etaStrip9.cr7.eta=9; out.etaStrip9.cr7.phi=7;
out.etaStrip9.cr8.energy=temporary[Eta+9][Phi+8].energy; out.etaStrip9.cr8.eta=9; out.etaStrip9.cr8.phi=8;
out.etaStrip9.cr9.energy=temporary[Eta+9][Phi+9].energy; out.etaStrip9.cr9.eta=9; out.etaStrip9.cr9.phi=9;
out.etaStrip9.cr10.energy=temporary[Eta+9][Phi+10].energy; out.etaStrip9.cr10.eta=9; out.etaStrip9.cr10.phi=10;
out.etaStrip9.cr11.energy=temporary[Eta+9][Phi+11].energy; out.etaStrip9.cr11.eta=9; out.etaStrip9.cr11.phi=11;
out.etaStrip9.cr12.energy=temporary[Eta+9][Phi+12].energy; out.etaStrip9.cr12.eta=9; out.etaStrip9.cr12.phi=12;
out.etaStrip9.cr13.energy=temporary[Eta+9][Phi+13].energy; out.etaStrip9.cr13.eta=9; out.etaStrip9.cr13.phi=13;
out.etaStrip9.cr14.energy=temporary[Eta+9][Phi+14].energy; out.etaStrip9.cr14.eta=9; out.etaStrip9.cr14.phi=14;
out.etaStrip9.cr15.energy=temporary[Eta+9][Phi+15].energy; out.etaStrip9.cr15.eta=9; out.etaStrip9.cr15.phi=15;
out.etaStrip9.cr16.energy=temporary[Eta+9][Phi+16].energy; out.etaStrip9.cr16.eta=9; out.etaStrip9.cr16.phi=16;
out.etaStrip9.cr17.energy=temporary[Eta+9][Phi+17].energy; out.etaStrip9.cr17.eta=9; out.etaStrip9.cr17.phi=17;
out.etaStrip9.cr18.energy=temporary[Eta+9][Phi+18].energy; out.etaStrip9.cr18.eta=9; out.etaStrip9.cr18.phi=18;
out.etaStrip9.cr19.energy=temporary[Eta+9][Phi+19].energy; out.etaStrip9.cr19.eta=9; out.etaStrip9.cr19.phi=19;

out.etaStrip10.cr0.energy=temporary[Eta+10][Phi+0].energy; out.etaStrip10.cr0.eta=10; out.etaStrip10.cr0.phi=0;
out.etaStrip10.cr1.energy=temporary[Eta+10][Phi+1].energy; out.etaStrip10.cr1.eta=10; out.etaStrip10.cr1.phi=1;
out.etaStrip10.cr2.energy=temporary[Eta+10][Phi+2].energy; out.etaStrip10.cr2.eta=10; out.etaStrip10.cr2.phi=2;
out.etaStrip10.cr3.energy=temporary[Eta+10][Phi+3].energy; out.etaStrip10.cr3.eta=10; out.etaStrip10.cr3.phi=3;
out.etaStrip10.cr4.energy=temporary[Eta+10][Phi+4].energy; out.etaStrip10.cr4.eta=10; out.etaStrip10.cr4.phi=4;
out.etaStrip10.cr5.energy=temporary[Eta+10][Phi+5].energy; out.etaStrip10.cr5.eta=10; out.etaStrip10.cr5.phi=5;
out.etaStrip10.cr6.energy=temporary[Eta+10][Phi+6].energy; out.etaStrip10.cr6.eta=10; out.etaStrip10.cr6.phi=6;
out.etaStrip10.cr7.energy=temporary[Eta+10][Phi+7].energy; out.etaStrip10.cr7.eta=10; out.etaStrip10.cr7.phi=7;
out.etaStrip10.cr8.energy=temporary[Eta+10][Phi+8].energy; out.etaStrip10.cr8.eta=10; out.etaStrip10.cr8.phi=8;
out.etaStrip10.cr9.energy=temporary[Eta+10][Phi+9].energy; out.etaStrip10.cr9.eta=10; out.etaStrip10.cr9.phi=9;
out.etaStrip10.cr10.energy=temporary[Eta+10][Phi+10].energy; out.etaStrip10.cr10.eta=10; out.etaStrip10.cr10.phi=10;
out.etaStrip10.cr11.energy=temporary[Eta+10][Phi+11].energy; out.etaStrip10.cr11.eta=10; out.etaStrip10.cr11.phi=11;
out.etaStrip10.cr12.energy=temporary[Eta+10][Phi+12].energy; out.etaStrip10.cr12.eta=10; out.etaStrip10.cr12.phi=12;
out.etaStrip10.cr13.energy=temporary[Eta+10][Phi+13].energy; out.etaStrip10.cr13.eta=10; out.etaStrip10.cr13.phi=13;
out.etaStrip10.cr14.energy=temporary[Eta+10][Phi+14].energy; out.etaStrip10.cr14.eta=10; out.etaStrip10.cr14.phi=14;
out.etaStrip10.cr15.energy=temporary[Eta+10][Phi+15].energy; out.etaStrip10.cr15.eta=10; out.etaStrip10.cr15.phi=15;
out.etaStrip10.cr16.energy=temporary[Eta+10][Phi+16].energy; out.etaStrip10.cr16.eta=10; out.etaStrip10.cr16.phi=16;
out.etaStrip10.cr17.energy=temporary[Eta+10][Phi+17].energy; out.etaStrip10.cr17.eta=10; out.etaStrip10.cr17.phi=17;
out.etaStrip10.cr18.energy=temporary[Eta+10][Phi+18].energy; out.etaStrip10.cr18.eta=10; out.etaStrip10.cr18.phi=18;
out.etaStrip10.cr19.energy=temporary[Eta+10][Phi+19].energy; out.etaStrip10.cr19.eta=10; out.etaStrip10.cr19.phi=19;

out.etaStrip11.cr0.energy=temporary[Eta+11][Phi+0].energy; out.etaStrip11.cr0.eta=11; out.etaStrip11.cr0.phi=0;
out.etaStrip11.cr1.energy=temporary[Eta+11][Phi+1].energy; out.etaStrip11.cr1.eta=11; out.etaStrip11.cr1.phi=1;
out.etaStrip11.cr2.energy=temporary[Eta+11][Phi+2].energy; out.etaStrip11.cr2.eta=11; out.etaStrip11.cr2.phi=2;
out.etaStrip11.cr3.energy=temporary[Eta+11][Phi+3].energy; out.etaStrip11.cr3.eta=11; out.etaStrip11.cr3.phi=3;
out.etaStrip11.cr4.energy=temporary[Eta+11][Phi+4].energy; out.etaStrip11.cr4.eta=11; out.etaStrip11.cr4.phi=4;
out.etaStrip11.cr5.energy=temporary[Eta+11][Phi+5].energy; out.etaStrip11.cr5.eta=11; out.etaStrip11.cr5.phi=5;
out.etaStrip11.cr6.energy=temporary[Eta+11][Phi+6].energy; out.etaStrip11.cr6.eta=11; out.etaStrip11.cr6.phi=6;
out.etaStrip11.cr7.energy=temporary[Eta+11][Phi+7].energy; out.etaStrip11.cr7.eta=11; out.etaStrip11.cr7.phi=7;
out.etaStrip11.cr8.energy=temporary[Eta+11][Phi+8].energy; out.etaStrip11.cr8.eta=11; out.etaStrip11.cr8.phi=8;
out.etaStrip11.cr9.energy=temporary[Eta+11][Phi+9].energy; out.etaStrip11.cr9.eta=11; out.etaStrip11.cr9.phi=9;
out.etaStrip11.cr10.energy=temporary[Eta+11][Phi+10].energy; out.etaStrip11.cr10.eta=11; out.etaStrip11.cr10.phi=10;
out.etaStrip11.cr11.energy=temporary[Eta+11][Phi+11].energy; out.etaStrip11.cr11.eta=11; out.etaStrip11.cr11.phi=11;
out.etaStrip11.cr12.energy=temporary[Eta+11][Phi+12].energy; out.etaStrip11.cr12.eta=11; out.etaStrip11.cr12.phi=12;
out.etaStrip11.cr13.energy=temporary[Eta+11][Phi+13].energy; out.etaStrip11.cr13.eta=11; out.etaStrip11.cr13.phi=13;
out.etaStrip11.cr14.energy=temporary[Eta+11][Phi+14].energy; out.etaStrip11.cr14.eta=11; out.etaStrip11.cr14.phi=14;
out.etaStrip11.cr15.energy=temporary[Eta+11][Phi+15].energy; out.etaStrip11.cr15.eta=11; out.etaStrip11.cr15.phi=15;
out.etaStrip11.cr16.energy=temporary[Eta+11][Phi+16].energy; out.etaStrip11.cr16.eta=11; out.etaStrip11.cr16.phi=16;
out.etaStrip11.cr17.energy=temporary[Eta+11][Phi+17].energy; out.etaStrip11.cr17.eta=11; out.etaStrip11.cr17.phi=17;
out.etaStrip11.cr18.energy=temporary[Eta+11][Phi+18].energy; out.etaStrip11.cr18.eta=11; out.etaStrip11.cr18.phi=18;
out.etaStrip11.cr19.energy=temporary[Eta+11][Phi+19].energy; out.etaStrip11.cr19.eta=11; out.etaStrip11.cr19.phi=19;

out.etaStrip12.cr0.energy=temporary[Eta+12][Phi+0].energy; out.etaStrip12.cr0.eta=12; out.etaStrip12.cr0.phi=0;
out.etaStrip12.cr1.energy=temporary[Eta+12][Phi+1].energy; out.etaStrip12.cr1.eta=12; out.etaStrip12.cr1.phi=1;
out.etaStrip12.cr2.energy=temporary[Eta+12][Phi+2].energy; out.etaStrip12.cr2.eta=12; out.etaStrip12.cr2.phi=2;
out.etaStrip12.cr3.energy=temporary[Eta+12][Phi+3].energy; out.etaStrip12.cr3.eta=12; out.etaStrip12.cr3.phi=3;
out.etaStrip12.cr4.energy=temporary[Eta+12][Phi+4].energy; out.etaStrip12.cr4.eta=12; out.etaStrip12.cr4.phi=4;
out.etaStrip12.cr5.energy=temporary[Eta+12][Phi+5].energy; out.etaStrip12.cr5.eta=12; out.etaStrip12.cr5.phi=5;
out.etaStrip12.cr6.energy=temporary[Eta+12][Phi+6].energy; out.etaStrip12.cr6.eta=12; out.etaStrip12.cr6.phi=6;
out.etaStrip12.cr7.energy=temporary[Eta+12][Phi+7].energy; out.etaStrip12.cr7.eta=12; out.etaStrip12.cr7.phi=7;
out.etaStrip12.cr8.energy=temporary[Eta+12][Phi+8].energy; out.etaStrip12.cr8.eta=12; out.etaStrip12.cr8.phi=8;
out.etaStrip12.cr9.energy=temporary[Eta+12][Phi+9].energy; out.etaStrip12.cr9.eta=12; out.etaStrip12.cr9.phi=9;
out.etaStrip12.cr10.energy=temporary[Eta+12][Phi+10].energy; out.etaStrip12.cr10.eta=12; out.etaStrip12.cr10.phi=10;
out.etaStrip12.cr11.energy=temporary[Eta+12][Phi+11].energy; out.etaStrip12.cr11.eta=12; out.etaStrip12.cr11.phi=11;
out.etaStrip12.cr12.energy=temporary[Eta+12][Phi+12].energy; out.etaStrip12.cr12.eta=12; out.etaStrip12.cr12.phi=12;
out.etaStrip12.cr13.energy=temporary[Eta+12][Phi+13].energy; out.etaStrip12.cr13.eta=12; out.etaStrip12.cr13.phi=13;
out.etaStrip12.cr14.energy=temporary[Eta+12][Phi+14].energy; out.etaStrip12.cr14.eta=12; out.etaStrip12.cr14.phi=14;
out.etaStrip12.cr15.energy=temporary[Eta+12][Phi+15].energy; out.etaStrip12.cr15.eta=12; out.etaStrip12.cr15.phi=15;
out.etaStrip12.cr16.energy=temporary[Eta+12][Phi+16].energy; out.etaStrip12.cr16.eta=12; out.etaStrip12.cr16.phi=16;
out.etaStrip12.cr17.energy=temporary[Eta+12][Phi+17].energy; out.etaStrip12.cr17.eta=12; out.etaStrip12.cr17.phi=17;
out.etaStrip12.cr18.energy=temporary[Eta+12][Phi+18].energy; out.etaStrip12.cr18.eta=12; out.etaStrip12.cr18.phi=18;
out.etaStrip12.cr19.energy=temporary[Eta+12][Phi+19].energy; out.etaStrip12.cr19.eta=12; out.etaStrip12.cr19.phi=19;

out.etaStrip13.cr0.energy=temporary[Eta+13][Phi+0].energy; out.etaStrip13.cr0.eta=13; out.etaStrip13.cr0.phi=0;
out.etaStrip13.cr1.energy=temporary[Eta+13][Phi+1].energy; out.etaStrip13.cr1.eta=13; out.etaStrip13.cr1.phi=1;
out.etaStrip13.cr2.energy=temporary[Eta+13][Phi+2].energy; out.etaStrip13.cr2.eta=13; out.etaStrip13.cr2.phi=2;
out.etaStrip13.cr3.energy=temporary[Eta+13][Phi+3].energy; out.etaStrip13.cr3.eta=13; out.etaStrip13.cr3.phi=3;
out.etaStrip13.cr4.energy=temporary[Eta+13][Phi+4].energy; out.etaStrip13.cr4.eta=13; out.etaStrip13.cr4.phi=4;
out.etaStrip13.cr5.energy=temporary[Eta+13][Phi+5].energy; out.etaStrip13.cr5.eta=13; out.etaStrip13.cr5.phi=5;
out.etaStrip13.cr6.energy=temporary[Eta+13][Phi+6].energy; out.etaStrip13.cr6.eta=13; out.etaStrip13.cr6.phi=6;
out.etaStrip13.cr7.energy=temporary[Eta+13][Phi+7].energy; out.etaStrip13.cr7.eta=13; out.etaStrip13.cr7.phi=7;
out.etaStrip13.cr8.energy=temporary[Eta+13][Phi+8].energy; out.etaStrip13.cr8.eta=13; out.etaStrip13.cr8.phi=8;
out.etaStrip13.cr9.energy=temporary[Eta+13][Phi+9].energy; out.etaStrip13.cr9.eta=13; out.etaStrip13.cr9.phi=9;
out.etaStrip13.cr10.energy=temporary[Eta+13][Phi+10].energy; out.etaStrip13.cr10.eta=13; out.etaStrip13.cr10.phi=10;
out.etaStrip13.cr11.energy=temporary[Eta+13][Phi+11].energy; out.etaStrip13.cr11.eta=13; out.etaStrip13.cr11.phi=11;
out.etaStrip13.cr12.energy=temporary[Eta+13][Phi+12].energy; out.etaStrip13.cr12.eta=13; out.etaStrip13.cr12.phi=12;
out.etaStrip13.cr13.energy=temporary[Eta+13][Phi+13].energy; out.etaStrip13.cr13.eta=13; out.etaStrip13.cr13.phi=13;
out.etaStrip13.cr14.energy=temporary[Eta+13][Phi+14].energy; out.etaStrip13.cr14.eta=13; out.etaStrip13.cr14.phi=14;
out.etaStrip13.cr15.energy=temporary[Eta+13][Phi+15].energy; out.etaStrip13.cr15.eta=13; out.etaStrip13.cr15.phi=15;
out.etaStrip13.cr16.energy=temporary[Eta+13][Phi+16].energy; out.etaStrip13.cr16.eta=13; out.etaStrip13.cr16.phi=16;
out.etaStrip13.cr17.energy=temporary[Eta+13][Phi+17].energy; out.etaStrip13.cr17.eta=13; out.etaStrip13.cr17.phi=17;
out.etaStrip13.cr18.energy=temporary[Eta+13][Phi+18].energy; out.etaStrip13.cr18.eta=13; out.etaStrip13.cr18.phi=18;
out.etaStrip13.cr19.energy=temporary[Eta+13][Phi+19].energy; out.etaStrip13.cr19.eta=13; out.etaStrip13.cr19.phi=19;

out.etaStrip14.cr0.energy=temporary[Eta+14][Phi+0].energy; out.etaStrip14.cr0.eta=14; out.etaStrip14.cr0.phi=0;
out.etaStrip14.cr1.energy=temporary[Eta+14][Phi+1].energy; out.etaStrip14.cr1.eta=14; out.etaStrip14.cr1.phi=1;
out.etaStrip14.cr2.energy=temporary[Eta+14][Phi+2].energy; out.etaStrip14.cr2.eta=14; out.etaStrip14.cr2.phi=2;
out.etaStrip14.cr3.energy=temporary[Eta+14][Phi+3].energy; out.etaStrip14.cr3.eta=14; out.etaStrip14.cr3.phi=3;
out.etaStrip14.cr4.energy=temporary[Eta+14][Phi+4].energy; out.etaStrip14.cr4.eta=14; out.etaStrip14.cr4.phi=4;
out.etaStrip14.cr5.energy=temporary[Eta+14][Phi+5].energy; out.etaStrip14.cr5.eta=14; out.etaStrip14.cr5.phi=5;
out.etaStrip14.cr6.energy=temporary[Eta+14][Phi+6].energy; out.etaStrip14.cr6.eta=14; out.etaStrip14.cr6.phi=6;
out.etaStrip14.cr7.energy=temporary[Eta+14][Phi+7].energy; out.etaStrip14.cr7.eta=14; out.etaStrip14.cr7.phi=7;
out.etaStrip14.cr8.energy=temporary[Eta+14][Phi+8].energy; out.etaStrip14.cr8.eta=14; out.etaStrip14.cr8.phi=8;
out.etaStrip14.cr9.energy=temporary[Eta+14][Phi+9].energy; out.etaStrip14.cr9.eta=14; out.etaStrip14.cr9.phi=9;
out.etaStrip14.cr10.energy=temporary[Eta+14][Phi+10].energy; out.etaStrip14.cr10.eta=14; out.etaStrip14.cr10.phi=10;
out.etaStrip14.cr11.energy=temporary[Eta+14][Phi+11].energy; out.etaStrip14.cr11.eta=14; out.etaStrip14.cr11.phi=11;
out.etaStrip14.cr12.energy=temporary[Eta+14][Phi+12].energy; out.etaStrip14.cr12.eta=14; out.etaStrip14.cr12.phi=12;
out.etaStrip14.cr13.energy=temporary[Eta+14][Phi+13].energy; out.etaStrip14.cr13.eta=14; out.etaStrip14.cr13.phi=13;
out.etaStrip14.cr14.energy=temporary[Eta+14][Phi+14].energy; out.etaStrip14.cr14.eta=14; out.etaStrip14.cr14.phi=14;
out.etaStrip14.cr15.energy=temporary[Eta+14][Phi+15].energy; out.etaStrip14.cr15.eta=14; out.etaStrip14.cr15.phi=15;
out.etaStrip14.cr16.energy=temporary[Eta+14][Phi+16].energy; out.etaStrip14.cr16.eta=14; out.etaStrip14.cr16.phi=16;
out.etaStrip14.cr17.energy=temporary[Eta+14][Phi+17].energy; out.etaStrip14.cr17.eta=14; out.etaStrip14.cr17.phi=17;
out.etaStrip14.cr18.energy=temporary[Eta+14][Phi+18].energy; out.etaStrip14.cr18.eta=14; out.etaStrip14.cr18.phi=18;
out.etaStrip14.cr19.energy=temporary[Eta+14][Phi+19].energy; out.etaStrip14.cr19.eta=14; out.etaStrip14.cr19.phi=19;

return out ;
}

ecaltp_t bestOf2(const ecaltp_t& ecaltp0, const ecaltp_t& ecaltp1) {
        ecaltp_t x;
        x = (ecaltp0.energy > ecaltp1.energy)?ecaltp0:ecaltp1;

        return x;
}

ecaltp_t getPeakBin20N(const etaStrip_t& etaStrip){
//#pragma HLS PIPELINE II=2
#pragma HLS latency min=4

ecaltp_t best01 = bestOf2(etaStrip.cr0,etaStrip.cr1) ;
ecaltp_t best23 = bestOf2(etaStrip.cr2,etaStrip.cr3) ;
ecaltp_t best45 = bestOf2(etaStrip.cr4,etaStrip.cr5) ;
ecaltp_t best67 = bestOf2(etaStrip.cr6,etaStrip.cr7) ;
ecaltp_t best89 = bestOf2(etaStrip.cr8,etaStrip.cr9) ;
ecaltp_t best1011 = bestOf2(etaStrip.cr10,etaStrip.cr11) ;
ecaltp_t best1213 = bestOf2(etaStrip.cr12,etaStrip.cr13) ;
ecaltp_t best1415 = bestOf2(etaStrip.cr14,etaStrip.cr15) ;
ecaltp_t best1617 = bestOf2(etaStrip.cr16,etaStrip.cr17) ;
ecaltp_t best1819 = bestOf2(etaStrip.cr18,etaStrip.cr19) ;

ecaltp_t best0123 = bestOf2(best01,best23) ;
ecaltp_t best4567 = bestOf2(best45,best67) ;
ecaltp_t best891011 = bestOf2(best89,best1011) ;
ecaltp_t best12131415 = bestOf2(best1213,best1415) ;
ecaltp_t best16171819 = bestOf2(best1617,best1819) ;

ecaltp_t best01234567 = bestOf2(best0123,best4567) ;
ecaltp_t best89101112131415 = bestOf2(best891011,best12131415) ;

ecaltp_t best0to15 = bestOf2(best01234567,best89101112131415) ;
ecaltp_t bestOf20 = bestOf2(best0to15,best16171819) ;

return bestOf20 ;
}

crystalMax getPeakBin15N(const etaStripPeak_t& etaStrip){
//#pragma HLS PIPELINE II=2
#pragma HLS latency min=4

crystalMax x;

ecaltp_t best01 = bestOf2(etaStrip.pk0,etaStrip.pk1) ;
ecaltp_t best23 = bestOf2(etaStrip.pk2,etaStrip.pk3) ;
ecaltp_t best45 = bestOf2(etaStrip.pk4,etaStrip.pk5) ;
ecaltp_t best67 = bestOf2(etaStrip.pk6,etaStrip.pk7) ;
ecaltp_t best89 = bestOf2(etaStrip.pk8,etaStrip.pk9) ;
ecaltp_t best1011 = bestOf2(etaStrip.pk10,etaStrip.pk11) ;
ecaltp_t best1213 = bestOf2(etaStrip.pk12,etaStrip.pk13) ;

ecaltp_t best0123 = bestOf2(best01,best23) ;
ecaltp_t best4567 = bestOf2(best45,best67) ;
ecaltp_t best891011 = bestOf2(best89,best1011) ;
ecaltp_t best121314 = bestOf2(best1213,etaStrip.pk14) ;

ecaltp_t best01234567 = bestOf2(best0123,best4567);
ecaltp_t best891011121314 = bestOf2(best891011,best121314) ;

ecaltp_t bestOf15 = bestOf2(best01234567,best891011121314) ;

        x.energy = bestOf15.energy ;
        x.etaMax = bestOf15.eta ;
        x.phiMax = bestOf15.phi ;

return x ;
}

void getTowerEt(crystal tempX[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI], ap_uint<12> towerEt[12]){
        #pragma HLS PIPELINE II=6
        #pragma HLS latency min=4
        #pragma HLS ARRAY_PARTITION variable=tempX complete dim=0
        #pragma HLS ARRAY_PARTITION variable=towerEt complete dim=0


        ap_uint<10>  temp[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI] ;
        #pragma HLS ARRAY_PARTITION variable=temp complete dim=0

        region3x4_t towerCal;
        ap_uint<12> towerEtN[3][4][5] ;
        #pragma HLS ARRAY_PARTITION variable=towerEtN complete dim=0

        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
            temp[i][k] = tempX[i][k].energy ;
         }}

         for(loop i=0; i<CRYSTAL_IN_ETA; i=i+5){
              #pragma HLS UNROLL
              for(loop k=0; k<CRYSTAL_IN_PHI; k=k+5){
                 #pragma HLS UNROLL
                 towerEtN[i/5][k/5][0] = temp[i][k] + temp[i][k+1] + temp[i][k+2] + temp[i][k+3] + temp[i][k+4] ;
                 towerEtN[i/5][k/5][1] = temp[i+1][k] + temp[i+1][k+1] + temp[i+1][k+2] + temp[i+1][k+3] + temp[i+1][k+4] ;
                 towerEtN[i/5][k/5][2] = temp[i+2][k] + temp[i+2][k+1] + temp[i+2][k+2] + temp[i+2][k+3] + temp[i+2][k+4] ;
                 towerEtN[i/5][k/5][3] = temp[i+3][k] + temp[i+3][k+1] + temp[i+3][k+2] + temp[i+3][k+3] + temp[i+3][k+4] ;
                 towerEtN[i/5][k/5][4] = temp[i+4][k] + temp[i+4][k+1] + temp[i+4][k+2] + temp[i+4][k+3] + temp[i+4][k+4] ;
          }}

                towerEt[0]= towerEtN[0][0][0] + towerEtN[0][0][1] + towerEtN[0][0][2] + towerEtN[0][0][3] + towerEtN[0][0][4] ;
                towerEt[1]= towerEtN[0][1][0] + towerEtN[0][1][1] + towerEtN[0][1][2] + towerEtN[0][1][3] + towerEtN[0][1][4] ;
                towerEt[2]= towerEtN[0][2][0] + towerEtN[0][2][1] + towerEtN[0][2][2] + towerEtN[0][2][3] + towerEtN[0][2][4] ;
                towerEt[3]= towerEtN[0][3][0] + towerEtN[0][3][1] + towerEtN[0][3][2] + towerEtN[0][3][3] + towerEtN[0][3][4] ;
                towerEt[4]= towerEtN[1][0][0] + towerEtN[1][0][1] + towerEtN[1][0][2] + towerEtN[1][0][3] + towerEtN[1][0][4] ;
                towerEt[5]= towerEtN[1][1][0] + towerEtN[1][1][1] + towerEtN[1][1][2] + towerEtN[1][1][3] + towerEtN[1][1][4] ;
                towerEt[6]= towerEtN[1][2][0] + towerEtN[1][2][1] + towerEtN[1][2][2] + towerEtN[1][2][3] + towerEtN[1][2][4] ;
                towerEt[7]= towerEtN[1][3][0] + towerEtN[1][3][1] + towerEtN[1][3][2] + towerEtN[1][3][3] + towerEtN[1][3][4] ;
                towerEt[8]= towerEtN[2][0][0] + towerEtN[2][0][1] + towerEtN[2][0][2] + towerEtN[2][0][3] + towerEtN[2][0][4] ;
                towerEt[9]= towerEtN[2][1][0] + towerEtN[2][1][1] + towerEtN[2][1][2] + towerEtN[2][1][3] + towerEtN[2][1][4] ;
                towerEt[10]= towerEtN[2][2][0] + towerEtN[2][2][1] + towerEtN[2][2][2] + towerEtN[2][2][3] + towerEtN[2][2][4] ;
                towerEt[11]= towerEtN[2][3][0] + towerEtN[2][3][1] + towerEtN[2][3][2] + towerEtN[2][3][3] + towerEtN[2][3][4] ;

}

clusterInfo getClusterPosition(const ecalRegion_t& ecalRegion){
#pragma HLS latency min=4

        etaStripPeak_t etaStripPeak;
        clusterInfo cluster ;


                etaStripPeak.pk0 = getPeakBin20N(ecalRegion.etaStrip0);
                etaStripPeak.pk1 = getPeakBin20N(ecalRegion.etaStrip1);
                etaStripPeak.pk2 = getPeakBin20N(ecalRegion.etaStrip2);
                etaStripPeak.pk3 = getPeakBin20N(ecalRegion.etaStrip3);
                etaStripPeak.pk4 = getPeakBin20N(ecalRegion.etaStrip4);
                etaStripPeak.pk5 = getPeakBin20N(ecalRegion.etaStrip5);
                etaStripPeak.pk6 = getPeakBin20N(ecalRegion.etaStrip6);
                etaStripPeak.pk7 = getPeakBin20N(ecalRegion.etaStrip7);
                etaStripPeak.pk8 = getPeakBin20N(ecalRegion.etaStrip8);
                etaStripPeak.pk9 = getPeakBin20N(ecalRegion.etaStrip9);
                etaStripPeak.pk10 = getPeakBin20N(ecalRegion.etaStrip10);
                etaStripPeak.pk11 = getPeakBin20N(ecalRegion.etaStrip11);
                etaStripPeak.pk12 = getPeakBin20N(ecalRegion.etaStrip12);
                etaStripPeak.pk13 = getPeakBin20N(ecalRegion.etaStrip13);
                etaStripPeak.pk14 = getPeakBin20N(ecalRegion.etaStrip14);

        crystalMax peakIn15;
        peakIn15 = getPeakBin15N(etaStripPeak);

        cluster.seedEnergy = peakIn15.energy ;
        cluster.energy = 0 ;
        cluster.etaMax = peakIn15.etaMax ;
        cluster.phiMax = peakIn15.phiMax ;
        cluster.brems = 0 ;
        cluster.et5x5 = 0 ;
        cluster.et2x5 = 0 ;

return cluster ;
}

Cluster packCluster(ap_uint<15>& clusterEt, ap_uint<5>& etaMax_t, ap_uint<5>& phiMax_t){
        
        ap_uint<12> peggedEt;
        Cluster pack;

        ap_uint<5> towerEta = (etaMax_t)/5;
        ap_uint<2> towerPhi = (phiMax_t)/5;
        ap_uint<3> clusterEta = etaMax_t - 5*towerEta;
        ap_uint<3> clusterPhi = phiMax_t - 5*towerPhi;

        peggedEt = (clusterEt > 0xFFF)? (ap_uint<12>)0xFFF : (ap_uint<12>) clusterEt;

        pack = Cluster(peggedEt, towerEta, towerPhi, clusterEta, clusterPhi, 0);

return pack;
}

void RemoveTmp(crystal temp[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI], ap_uint<5> seed_eta,  ap_uint<5> seed_phi, ap_uint<2> brems  ){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
#pragma HLS latency min=3

        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
//                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
            if(i>=seed_eta-1 && i<=seed_eta+1 && k>=seed_phi-2 && k<=seed_phi+2)  temp[i][k].energy = 0 ;
         }}

        if(brems == 1){
        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
//                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
            if(i>=seed_eta-1 && i<=seed_eta+1 && k>=seed_phi-2-5 && k<=seed_phi+2-5)  temp[i][k].energy = 0 ;
                        }
                }
         }

        if(brems == 2){
        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
//                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
            if(i>=seed_eta-1 && i<=seed_eta+1 && k>=seed_phi-2+5 && k<=seed_phi+2+5)  temp[i][k].energy = 0 ;
         }}}
}

clusterInfo getBremsValuesPos(crystal tempX[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI], ap_uint<5> seed_eta,  ap_uint<5> seed_phi ){
#pragma HLS ARRAY_PARTITION variable=tempX complete dim=0
#pragma HLS latency min=6

        ap_uint<12> temp[CRYSTAL_IN_ETA+2][CRYSTAL_IN_PHI+4] ;
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0

        ap_uint<12> phi0eta[3], phi1eta[3], phi2eta[3], phi3eta[3], phi4eta[3] ;
#pragma HLS ARRAY_PARTITION variable=phi0eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi1eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi2eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi3eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi4eta complete dim=0

        ap_uint<12> eta_slice[3] ;
#pragma HLS ARRAY_PARTITION variable=eta_slice complete dim=0

clusterInfo cluster_tmp;

        for(loop i=0; i<CRYSTAL_IN_ETA+2; i++){
                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI+4; k++){
                        #pragma HLS UNROLL
            temp[i][k] = 0 ;
         }}

        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
                        #pragma HLS UNROLL
           for(loop k=5; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
            temp[i+1][k-3] = tempX[i][k].energy ;
         }}


        ap_uint<6> seed_eta1,  seed_phi1 ;

        seed_eta1 = seed_eta ; //to start from corner
        seed_phi1 = seed_phi ; //to start from corner
// now we are in the left bottom corner 

        for(loop j=0; j<CRYSTAL_IN_ETA; j++){
//                        #pragma HLS UNROLL
            if(j == seed_eta1)
              {
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
              if(k == seed_phi1)
                 {
                  phi0eta[0] = temp[j][k];
                  phi1eta[0] = temp[j][k+1];
                  phi2eta[0] = temp[j][k+2];
                  phi3eta[0] = temp[j][k+3];
                  phi4eta[0] = temp[j][k+4];

                  phi0eta[1] = temp[j+1][k];
                  phi1eta[1] = temp[j+1][k+1];
                  phi2eta[1] = temp[j+1][k+2];
                  phi3eta[1] = temp[j+1][k+3];
                  phi4eta[1] = temp[j+1][k+4];
                        
                  phi0eta[2] = temp[j+2][k];
                  phi1eta[2] = temp[j+2][k+1];
                  phi2eta[2] = temp[j+2][k+2];
                  phi3eta[2] = temp[j+2][k+3];
                  phi4eta[2] = temp[j+2][k+4];

		continue ;
               }}
          }}


       for(loop i=0; i<3; i++){
                        #pragma HLS UNROLL
          eta_slice[i] = phi0eta[i] + phi1eta[i] + phi2eta[i] + phi3eta[i] + phi4eta[i] ;
        }
         cluster_tmp.energy=eta_slice[0] + eta_slice[1] + eta_slice[2] ;

return cluster_tmp ;
}

clusterInfo getBremsValuesNeg(crystal tempX[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI], ap_uint<5> seed_eta,  ap_uint<5> seed_phi ){
#pragma HLS ARRAY_PARTITION variable=tempX complete dim=0
#pragma HLS latency min=6

        ap_uint<12> temp[CRYSTAL_IN_ETA+2][CRYSTAL_IN_PHI+4] ;
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0

        ap_uint<12> phi0eta[3], phi1eta[3], phi2eta[3], phi3eta[3], phi4eta[3] ;
#pragma HLS ARRAY_PARTITION variable=phi0eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi1eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi2eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi3eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi4eta complete dim=0

        ap_uint<12> eta_slice[3] ;
#pragma HLS ARRAY_PARTITION variable=eta_slice complete dim=0

clusterInfo cluster_tmp;

        for(loop i=0; i<CRYSTAL_IN_ETA+2; i++){
                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI+4; k++){
                        #pragma HLS UNROLL
            temp[i][k] = 0 ;
         }}

        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI-5; k++){
                        #pragma HLS UNROLL
            temp[i+1][k+7] = tempX[i][k].energy ;
         }}


        ap_uint<6> seed_eta1,  seed_phi1 ;

        seed_eta1 = seed_eta ; //to start from corner
        seed_phi1 = seed_phi ; //to start from corner
// now we are in the left bottom corner 

        for(loop j=0; j<CRYSTAL_IN_ETA; j++){
//                        #pragma HLS UNROLL
            if(j == seed_eta1)
              {
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
                if(k == seed_phi1)
                 {
                  phi0eta[0] = temp[j][k];
                  phi1eta[0] = temp[j][k+1];
                  phi2eta[0] = temp[j][k+2];
                  phi3eta[0] = temp[j][k+3];
                  phi4eta[0] = temp[j][k+4];

                  phi0eta[1] = temp[j+1][k];
                  phi1eta[1] = temp[j+1][k+1];
                  phi2eta[1] = temp[j+1][k+2];
                  phi3eta[1] = temp[j+1][k+3];
                  phi4eta[1] = temp[j+1][k+4];
                        
                  phi0eta[2] = temp[j+2][k];
                  phi1eta[2] = temp[j+2][k+1];
                  phi2eta[2] = temp[j+2][k+2];
                  phi3eta[2] = temp[j+2][k+3];
                  phi4eta[2] = temp[j+2][k+4];

		continue ;
               }}
          }}


       for(loop i=0; i<3; i++){
                        #pragma HLS UNROLL
          eta_slice[i] = phi0eta[i] + phi1eta[i] + phi2eta[i] + phi3eta[i] + phi4eta[i] ;
        }
         cluster_tmp.energy=eta_slice[0] + eta_slice[1] + eta_slice[2] ;

return cluster_tmp ;
}


clusterInfo getClusterValues(crystal tempX[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI], ap_uint<5> seed_eta,  ap_uint<5> seed_phi ){
#pragma HLS ARRAY_PARTITION variable=tempX complete dim=0
#pragma HLS latency min=6

        ap_uint<12> temp[CRYSTAL_IN_ETA+4][CRYSTAL_IN_PHI+4] ;
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0

        ap_uint<12> phi0eta[5], phi1eta[5], phi2eta[5], phi3eta[5], phi4eta[5] ;
#pragma HLS ARRAY_PARTITION variable=phi0eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi1eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi2eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi3eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=phi4eta complete dim=0

        ap_uint<12> eta_slice[5] ;
#pragma HLS ARRAY_PARTITION variable=eta_slice complete dim=0


        ap_uint<12> et2x5_1Tot, et2x5_2Tot, etSum2x5 ;
        ap_uint<12> et5x5Tot ;

clusterInfo cluster_tmp;

        for(loop i=0; i<CRYSTAL_IN_ETA+4; i++){
                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI+4; k++){
                        #pragma HLS UNROLL
            temp[i][k] = 0 ;
         }}

        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
                        #pragma HLS UNROLL
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
            temp[i+2][k+2] = tempX[i][k].energy ;
         }}


        ap_uint<6> seed_eta1,  seed_phi1 ;

        seed_eta1 = seed_eta ; //to start from corner
        seed_phi1 = seed_phi ; //to start from corner
// now we are in the left bottom corner 

        for(loop j=0; j<CRYSTAL_IN_ETA; j++){
//                        #pragma HLS UNROLL
            if(j == seed_eta1)
              {
           for(loop k=0; k<CRYSTAL_IN_PHI; k++){
                        #pragma HLS UNROLL
              if(k == seed_phi1)
                 {
                  phi0eta[0] = temp[j][k];
                  phi1eta[0] = temp[j][k+1];
                  phi2eta[0] = temp[j][k+2];
                  phi3eta[0] = temp[j][k+3];
                  phi4eta[0] = temp[j][k+4];

                  phi0eta[1] = temp[j+1][k];
                  phi1eta[1] = temp[j+1][k+1];
                  phi2eta[1] = temp[j+1][k+2];
                  phi3eta[1] = temp[j+1][k+3];
                  phi4eta[1] = temp[j+1][k+4];
                        
                  phi0eta[2] = temp[j+2][k];
                  phi1eta[2] = temp[j+2][k+1];
                  phi2eta[2] = temp[j+2][k+2];
                  phi3eta[2] = temp[j+2][k+3];
                  phi4eta[2] = temp[j+2][k+4];

                  phi0eta[3] = temp[j+3][k];
                  phi1eta[3] = temp[j+3][k+1];
                  phi2eta[3] = temp[j+3][k+2];
                  phi3eta[3] = temp[j+3][k+3];
                  phi4eta[3] = temp[j+3][k+4];

                  phi0eta[4] = temp[j+4][k];
                  phi1eta[4] = temp[j+4][k+1];
                  phi2eta[4] = temp[j+4][k+2];
                  phi3eta[4] = temp[j+4][k+3];
                  phi4eta[4] = temp[j+4][k+4];

		continue ;
               }}
          }}


       for(loop i=0; i<5; i++){
                        #pragma HLS UNROLL
          eta_slice[i] = phi0eta[i] + phi1eta[i] + phi2eta[i] + phi3eta[i] + phi4eta[i] ;
        }
         cluster_tmp.energy=eta_slice[1] + eta_slice[2] + eta_slice[3] ;

          et5x5Tot = eta_slice[0] + eta_slice[1] + eta_slice[2] + eta_slice[3] + eta_slice[4] ;
          et2x5_1Tot = eta_slice[1] + eta_slice[2] ;
          et2x5_2Tot = eta_slice[2] + eta_slice[3] ;


          if(et2x5_1Tot >= et2x5_2Tot) etSum2x5 = et2x5_1Tot ;
          else etSum2x5 = et2x5_2Tot ;

          cluster_tmp.et5x5 = et5x5Tot ;
          cluster_tmp.et2x5 = etSum2x5 ;


return cluster_tmp ;
}


Cluster getRegion3x4(crystal temp[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI]){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
//#pragma HLS PIPELINE II=2
#pragma HLS latency min=24

Cluster returnCluster;
clusterInfo cluster_tmp;
clusterInfo cluster_tmpCenter;
clusterInfo cluster_tmpBneg;
clusterInfo cluster_tmpBpos;

ecalRegion_t ecalRegion;

        ecalRegion = initStructure(temp) ;

        cluster_tmp = getClusterPosition(ecalRegion) ;

        ap_uint<5> seed_phi = cluster_tmp.phiMax ;
        ap_uint<5> seed_eta = cluster_tmp.etaMax ;

        cluster_tmpCenter = getClusterValues(temp, seed_eta, seed_phi) ;
        cluster_tmpBneg = getBremsValuesNeg(temp, seed_eta, seed_phi) ;
        cluster_tmpBpos = getBremsValuesPos(temp, seed_eta, seed_phi) ;

        cluster_tmp.energy = cluster_tmpCenter.energy;

        cluster_tmp.brems = 0 ;

         if(cluster_tmpBneg.energy > cluster_tmpCenter.energy/8 && cluster_tmpBneg.energy > cluster_tmpBpos.energy) {
            cluster_tmp.energy = cluster_tmpCenter.energy + cluster_tmpBneg.energy ; cluster_tmp.brems = 1 ; }
         else if(cluster_tmpBpos.energy > cluster_tmpCenter.energy/8){
            cluster_tmp.energy = cluster_tmpCenter.energy + cluster_tmpBpos.energy ; cluster_tmp.brems = 2 ; }

//eta, phi, seed energy in cluster_tmp; energy and brems in cluster_tmp1

        returnCluster = packCluster(cluster_tmp.energy, cluster_tmp.etaMax, cluster_tmp.phiMax);

        RemoveTmp(temp, seed_eta, seed_phi, cluster_tmp.brems ) ;

return returnCluster;
}


void algo_top(ap_uint<384> link_in[N_INPUT_LINKS], ap_uint<384> link_out[N_OUTPUT_LINKS]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=6
#pragma HLS INTERFACE ap_ctrl_hs port=return

//#pragma HLS latency min=100

towerHCAL HCALRegion4x4_1[HCAL_TOWER_IN_ETA][HCAL_TOWER_IN_PHI], HCALRegion4x4_2[HCAL_TOWER_IN_ETA][HCAL_TOWER_IN_PHI];
#pragma HLS ARRAY_PARTITION variable=HCALRegion4x4_1 complete dim=0
#pragma HLS ARRAY_PARTITION variable=HCALRegion4x4_2 complete dim=0

crystal ECALReagion3x4_1[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI];
#pragma HLS ARRAY_PARTITION variable=ECALReagion3x4_1 complete dim=0

crystal ECALReagion3x4_2[CRYSTAL_IN_ETA][CRYSTAL_IN_PHI];
#pragma HLS ARRAY_PARTITION variable=ECALReagion3x4_2 complete dim=0

//creating 2 15x20 crystals temporary and temporary1

processInputLinks(link_in, ECALReagion3x4_1, ECALReagion3x4_2, HCALRegion4x4_1, HCALRegion4x4_2);

region3x4_t forTower_1, forTower_2;
Cluster forCluster1, forCluster2, forCluster3, forCluster4;
Cluster sort_clusterIn[Nbclusters];
Cluster sort_clusterOut[Nbclusters];

tower_t towerEt[24];

#pragma HLS ARRAY_PARTITION variable=sort_clusterIn complete dim=0
#pragma HLS ARRAY_PARTITION variable=sort_clusterOut complete dim=0
#pragma HLS ARRAY_PARTITION variable=towerEt complete dim=0


        sort_clusterIn[0] = getRegion3x4(ECALReagion3x4_1);
        sort_clusterIn[1] = getRegion3x4(ECALReagion3x4_1);
        sort_clusterIn[2] = getRegion3x4(ECALReagion3x4_1);
        sort_clusterIn[3] = getRegion3x4(ECALReagion3x4_1);

        forCluster1 =  getRegion3x4(ECALReagion3x4_2);
        ap_uint<5> towerEta1 = forCluster1.towerEta() + 3;
        sort_clusterIn[4] = Cluster(forCluster1.clusterEnergy(), towerEta1, forCluster1.towerPhi(), forCluster1.clusterEta(), forCluster1.clusterPhi(), forCluster1.satur());

        forCluster2 =  getRegion3x4(ECALReagion3x4_2);
        ap_uint<5> towerEta2 = forCluster2.towerEta() + 3;
        sort_clusterIn[5] = Cluster(forCluster2.clusterEnergy(), towerEta2, forCluster2.towerPhi(), forCluster2.clusterEta(), forCluster2.clusterPhi(), forCluster2.satur());

        forCluster3 =  getRegion3x4(ECALReagion3x4_2);
        ap_uint<5> towerEta3 = forCluster3.towerEta() + 3;
        sort_clusterIn[6] = Cluster(forCluster3.clusterEnergy(), towerEta3, forCluster3.towerPhi(), forCluster3.clusterEta(), forCluster3.clusterPhi(), forCluster3.satur());

        forCluster4 =  getRegion3x4(ECALReagion3x4_2);
        ap_uint<5> towerEta4 = forCluster4.towerEta() + 3;
        sort_clusterIn[7] = Cluster(forCluster4.clusterEnergy(), towerEta4, forCluster4.towerPhi(), forCluster4.clusterEta(), forCluster4.clusterPhi(), forCluster4.satur());

// sorting of 8 clusters

        bitonicSort8(sort_clusterIn, sort_clusterOut);
        
        ap_uint<12> towerEtHCAL1[12];
        ap_uint<12> towerEtHCAL2[12];
        #pragma HLS ARRAY_PARTITION variable=towerEtHCAL1 complete dim=0
        #pragma HLS ARRAY_PARTITION variable=towerEtHCAL2 complete dim=0

        towerEtHCAL1[0] = HCALRegion4x4_1[0][0].et ; towerEtHCAL1[1] = HCALRegion4x4_1[0][1].et ; towerEtHCAL1[2] = HCALRegion4x4_1[0][2].et ; towerEtHCAL1[3] = HCALRegion4x4_1[0][3].et ;
        towerEtHCAL1[4] = HCALRegion4x4_1[1][0].et ; towerEtHCAL1[5] = HCALRegion4x4_1[1][1].et ; towerEtHCAL1[6] = HCALRegion4x4_1[1][2].et ; towerEtHCAL1[7] = HCALRegion4x4_1[1][3].et ;
        towerEtHCAL1[8] = HCALRegion4x4_1[2][0].et ; towerEtHCAL1[9] = HCALRegion4x4_1[2][1].et ; towerEtHCAL1[10] = HCALRegion4x4_1[2][2].et ; towerEtHCAL1[11] = HCALRegion4x4_1[2][3].et ;

        towerEtHCAL2[0] = HCALRegion4x4_1[3][0].et ; towerEtHCAL2[1] = HCALRegion4x4_1[3][1].et ; towerEtHCAL2[2] = HCALRegion4x4_1[3][2].et ; towerEtHCAL2[3] = HCALRegion4x4_1[3][3].et ;
        towerEtHCAL2[4] = HCALRegion4x4_2[0][0].et ; towerEtHCAL2[5] = HCALRegion4x4_2[0][1].et ; towerEtHCAL2[6] = HCALRegion4x4_2[0][2].et ; towerEtHCAL2[7] = HCALRegion4x4_2[0][3].et ;
        towerEtHCAL2[8] = HCALRegion4x4_2[1][0].et ; towerEtHCAL2[9] = HCALRegion4x4_2[1][1].et ; towerEtHCAL2[10] = HCALRegion4x4_2[1][2].et ; towerEtHCAL2[11] = HCALRegion4x4_2[1][3].et ;

        ap_uint<12> towerEtECAL1[12];
        ap_uint<12> towerEtECAL2[12];
        #pragma HLS ARRAY_PARTITION variable=towerEtECAL1 complete dim=0
        #pragma HLS ARRAY_PARTITION variable=towerEtECAL2 complete dim=0

        getTowerEt(ECALReagion3x4_1, towerEtECAL1);
        getTowerEt(ECALReagion3x4_2, towerEtECAL2);

        ap_uint<12> SumEH ;
        for(loop i=0; i<12; i++){
                #pragma HLS UNROLL
        SumEH = towerEtECAL1[i]+towerEtHCAL1[i] ;
        towerEt[i] = tower_t(SumEH, 0, 0);
        SumEH = towerEtECAL2[i]+towerEtHCAL2[i] ;
        towerEt[i+12] = tower_t(SumEH, 0, 0);
        }

        /*---------------------------------link 1------------------------------------*/
        ap_uint<32> start1_1 = 0;
        link_out[0] = 0;
        for(loop oLink=0; oLink<6; oLink++){
        #pragma HLS UNROLL
            ap_uint<32> end = start1_1 + 15;
            link_out[0].range(end, start1_1) = towerEt[oLink];
            start1_1 += 16;
        }

        ap_uint<32> start2_1 = 96;
        for(loop oLink=0; oLink<2; oLink++){
        #pragma HLS UNROLL
            ap_uint<32> end = start2_1 + 27;
            link_out[0].range(end, start2_1) = sort_clusterOut[oLink];
            start2_1 += 28;
        }

        /*---------------------------------link 2------------------------------------*/
        ap_uint<32> start1_2 = 0;
        link_out[1] = 0;
        for(loop oLink=0; oLink<6; oLink++){
        #pragma HLS UNROLL
                ap_uint<32> end = start1_2 + 15;
                link_out[1].range(end, start1_2) = towerEt[oLink+6];
                start1_2 += 16;
        }

        ap_uint<32> start2_2 = 96;
        for(loop oLink=0; oLink<2; oLink++){
        #pragma HLS UNROLL
                ap_uint<32> end = start2_2 + 27;
                link_out[1].range(end, start2_2) = sort_clusterOut[oLink+2];
                start2_2 += 28;
        }

        /*---------------------------------link 3------------------------------------*/
        ap_uint<32> start1_3 = 0;
        link_out[2] = 0;
        for(loop oLink=0; oLink<6; oLink++){
        #pragma HLS UNROLL
                ap_uint<32> end = start1_3 + 15;
                link_out[2].range(end, start1_3) = towerEt[oLink+12];
                start1_3 += 16;
        }

        ap_uint<32> start2_3 = 96;
        for(loop oLink=0; oLink<2; oLink++){
        #pragma HLS UNROLL
                ap_uint<32> end = start2_3 + 27;
                link_out[2].range(end, start2_3) = sort_clusterOut[oLink+4];
                start2_3 += 28;
        }

        /*---------------------------------link 4------------------------------------*/
        ap_uint<32> start1_4 = 0;
        link_out[3] = 0;
        for(loop oLink=0; oLink<6; oLink++){
        #pragma HLS UNROLL
                ap_uint<32> end = start1_4 + 15;
                link_out[3].range(end, start1_4) = towerEt[oLink+18];
                start1_4 += 16;
        }

        ap_uint<32> start2_4 = 96;
        for(loop oLink=0; oLink<2; oLink++){
        #pragma HLS UNROLL
                ap_uint<32> end = start2_4 + 27;
                link_out[3].range(end, start2_4) = sort_clusterOut[oLink+6];
                start2_4 += 28;
        }


}


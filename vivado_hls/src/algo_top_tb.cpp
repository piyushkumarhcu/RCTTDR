#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdint.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "algo_top.h"
#include "algo_top_parameters.h"

using namespace std;

int main() {

	ap_uint<384> link_in[N_INPUT_LINKS];
	ap_uint<384> link_out[N_OUTPUT_LINKS];

    size_t start = 0;
    size_t end = 13;

    for(size_t i=0; i<N_INPUT_LINKS; i++){
    	   link_in[i] = 0;
       }

    ap_uint<6> wordId, wordId1, startId ;
    for(size_t i=0; i<CRYSTAL_IN_ETA; i++){
        for(size_t j=0; j<CRYSTAL_IN_PHI; j++){
            wordId = (i/5)*4+(j/5) ;
            startId = (i%5)*5+(j%5) ;
            start = startId*14 ; end = start + 13 ;
// temporary
        		link_in[wordId].range(end, start) = 0 ; //  [i][j] crystal in 15:20 

                 if(i == 0 && j == 0) link_in[wordId].range(end, start) = 10 ;
                 if(i == 4 && j == 4) link_in[wordId].range(end, start) = 15 ;
                 if(i == 4 && j == 9) link_in[wordId].range(end, start) = 20 ;
                 if(i == 3 && j == 13) link_in[wordId].range(end, start) = 13 ;
                 if(i == 10 && j == 2) link_in[wordId].range(end, start) = 25 ;
                 if(i == 12 && j == 5) link_in[wordId].range(end, start) = 30 ;
                 if(i == 11 && j == 11) link_in[wordId].range(end, start) = 40 ;
                 if(i == 13 && j == 15) link_in[wordId].range(end, start) = 16 ;
                 if(i == 9 && j == 19) link_in[wordId].range(end, start) = 100 ;
                 if(i == 0 && j == 19) link_in[wordId].range(end, start) = 54 ;

//temporary1
                       wordId1 = wordId + 12 ;
                       link_in[wordId1].range(end, start) = 0 ; //  [i][j] crystal in 15:20 

                 if(i == 1 && j == 2) link_in[wordId1].range(end, start) = 11 ;
                 if(i == 4 && j == 6) link_in[wordId1].range(end, start) = 18 ;
                 if(i == 4 && j == 9) link_in[wordId1].range(end, start) = 23 ;
                 if(i == 3 && j == 13) link_in[wordId1].range(end, start) = 33 ;
                 if(i == 8 && j == 3) link_in[wordId1].range(end, start) = 27 ;
                 if(i == 13 && j == 5) link_in[wordId1].range(end, start) = 31 ;
                 if(i == 11 && j == 9) link_in[wordId1].range(end, start) = 60 ;
                 if(i == 7 && j == 15) link_in[wordId1].range(end, start) = 17 ;
                 if(i == 1 && j == 19) link_in[wordId1].range(end, start) = 200 ;
                 if(i == 8 && j == 19) link_in[wordId1].range(end, start) = 54 ;

         	}
		}

      start = 0; end = 15;
    for(size_t i=0; i<HCAL_TOWER_IN_ETA; i++){
        for(size_t j=0; j<HCAL_TOWER_IN_PHI; j++){
        	link_in[24].range(end, start) = 0 ; 
            if(i == 0 && j == 0) link_in[24].range(end, start) = 66 ;
            if(i == 0 && j == 1) link_in[24].range(end, start) = 67 ;
            if(i == 0 && j == 2) link_in[24].range(end, start) = 68 ;
            if(i == 0 && j == 3) link_in[24].range(end, start) = 69 ;
            if(i == 3 && j == 0) link_in[24].range(end, start) = 10 ;
            if(i == 3 && j == 1) link_in[24].range(end, start) = 20 ;
            if(i == 3 && j == 2) link_in[24].range(end, start) = 30 ;
        	if(i == 3 && j == 3) link_in[24].range(end, start) = 40 ;
            link_in[25].range(end, start) = 0 ; 
            if(i == 0 && j == 0) link_in[25].range(end, start) = 88 ;
            if(i == 1 && j == 0) link_in[25].range(end, start) = 77 ;
            start += 16; end += 16;
        }
	}
    /*for(size_t i=0; i<N_INPUT_LINKS; i++){
    	cout << hex << link_in[i] << endl;
    }

    cout << endl;*/

	// Run the algorithm

	  algo_top(link_in, link_out);

	  	cout << hex << "link_out[0]: " << link_out[0] << endl;
	  	cout << hex << "link_out[1]: " << link_out[1] << endl;
	  	cout << hex << "link_out[2]: " << link_out[2] << endl;
	  	cout << hex << "link_out[3]: " << link_out[3] << endl;
	  cout << "printing towers et" << endl;

	  		start = 0;
	  		for(loop oLink=0; oLink<6; oLink++){
	  			size_t end = start + 15;
	  			cout << link_out[0].range(end, start) << endl;
	  			start += 16;
	  		}

	  		start = 0;
	  		for(loop oLink=0; oLink<6; oLink++){
	  			size_t end = start + 15;
	  			cout << link_out[1].range(end, start) << endl;
	  			start += 16;
	  		}

	  		start = 0;
	  		for(loop oLink=0; oLink<6; oLink++){
	  			size_t end = start + 15;
	  			cout << link_out[2].range(end, start) << endl;
	  			start += 16;
	  		}

	  		start = 0;
	  		for(loop oLink=0; oLink<6; oLink++){
	  			size_t end = start + 15;
	  			cout << link_out[3].range(end, start) << endl;
	  			start += 16;
	  		}

	  		cout << "printing cluster et" << endl;

	  		cout << link_out[0].range(107, 96) << endl;
	  		cout << link_out[0].range(135, 124) << endl;
	  		cout << link_out[1].range(107, 96) << endl;
	  		cout << link_out[1].range(135, 124) << endl;
	  		cout << link_out[2].range(107, 96) << endl;
	  		cout << link_out[2].range(135, 124) << endl;
	  		cout << link_out[3].range(107, 96) << endl;
	  		cout << link_out[3].range(135, 124) << endl;

return 0;

}




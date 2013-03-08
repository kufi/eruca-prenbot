/*
 * PID.c
 *
 *  Created on: Dec 14, 2012
 *      Author: 8460p
 */
#include "MKL25Z4.h"
#include "PID.h"



void initPIDA(int maximalausschlag_,int p_factor_,int i_factor_,int d_factor_){
	p_factorA=p_factor_;
	i_factorA=i_factor_;
	d_factorA=d_factor_;
	maximalausschlagA=maximalausschlag_;
	maximalfehlerA=200;
	p_maximalausschlagA=500;
	sumirterfehlerA =0;
	maximalfehelersummeA=200;
	i_maximalausschlagA =100;
	lezterFunktionswertA=0;
}

int pidA(int sollwert,int istwert){
	int temp;
	int ret;
	
	errorA = sollwert - istwert;
	
	//Calculate Pterm and limit error overflow
	if (errorA > maximalfehlerA){
	    p_resultatA = p_maximalausschlagA;
	  }
	  else if (errorA < -maximalfehlerA){
	    p_resultatA = -p_maximalausschlagA;
	  }
	  else{
	    p_resultatA = p_factorA * errorA;
	  }
	
	// Calculate Iterm and limit integral runaway
	  temp = sumirterfehlerA + errorA;
	  if(temp > maximalfehelersummeA){
		 i_resultatA = i_maximalausschlagA;
		 sumirterfehlerA = i_maximalausschlagA;
	  }
	  else if(temp < -maximalfehelersummeA){
	    i_resultatA = -i_maximalausschlagA;
	    sumirterfehlerA = -i_maximalausschlagA;
	  }
	  else{
		  sumirterfehlerA = temp;
	      i_resultatA = i_factorA * temp;
	  }
	  // Calculate Dterm
	    d_resultatA = d_factorA * (lezterFunktionswertA - istwert);

	    lezterFunktionswertA = istwert;

	    ret = p_resultatA+i_resultatA+d_resultatA;
	    
	    if(ret > maximalausschlagA){
	      ret = maximalausschlagA;
	    }
	    else if(ret < -maximalausschlagA){
	      ret = -maximalausschlagA;
	    }
	    return ret;
}


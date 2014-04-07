#include <vector>
#include <TH2F.h>
#include <iostream>
#include <cmath>
#include <TVector2.h>
#include <TFile.h>
#include "TStyle.h"
#include <string>
#include "TROOT.h"
//#include "/afs/desy.de/user/a/adraeger/xxl/newStudies/CMSSW_5_3_5/src/RA2Classic/AdditionalInputFiles/RA2PlottingStyle.h"
// global used functions

#ifndef _mal2_hpp_
#define _mal2_hpp_
double deltaR(double eta1, double phi1, double eta2, double phi2);
double MTWCalculator(double metPt, double metPhi, double lepPt, double lepPhi);
double effDown(double eff, double down);
double effUp(double eff, double up);
std::pair <double,double> DRToClosestJet(UShort_t cleanPatJetsAK5CaloNum, Float_t cleanPatJetsAK5CaloPt[60], Float_t cleanPatJetsAK5CaloEta[60], Float_t cleanPatJetsAK5CaloPhi[60], Float_t lepPt, Float_t lepEta, Float_t lepPhi);
// global varialbes and input files
bool debug_;
bool filters_;
bool recomputeEff_, useSavedEff_;
TDirectory *prediction_;
// input file names
TString effComputInputFileName, predictionInputFileName;
// output
TFile *outPutFile_, *efficienciesTAP_;
TString predictionName_;
//global baseline cuts
double baselineHT_, baselineMHT_, baselineNJets_, deltaPhi1_, deltaPhi2_, deltaPhi3_;
// lost lepton varaibles and cuts
Float_t mtwCut_,DiLepCorrection_, DiLepCorrectionUp_, DiLepCorrectionDown_, MTWUncertaintyUp_, MTWUncertaintyDown_;
Float_t MuAccUncertaintyUp_, MuAccUncertaintyDown_, ElecAccUncertaintyUp_, ElecAccUncertaintyDown_, diBosonDown_, NonClosureLowNJet_, NonClosureHighNJet_;



// eff TH2F
TH2F *MuonIsoLow_, *MuonIso0_, *MuonIso1_, *MuonIso2_; 
TH2F *MuonRecoLow_, *MuonReco0_, *MuonReco1_, *MuonReco2_; 
TH2F *MuonAcc_;
TH2F *ElecIsoLow_, *ElecIso0_, *ElecIso1_, *ElecIso2_; 
TH2F *ElecRecoLow_, *ElecReco0_, *ElecReco1_, *ElecReco2_; 
TH2F *ElecAcc_;
TH1F *MTWNJet_;
TH2F *MTWMHTNJet_;

TH2F *MC_TAP_mu_iso_eff, *Data_TAP_mu_iso_eff, *MC_TAP_mu_reco_eff, *Data_TAP_mu_reco_eff;
TH2F *MC_TAP_elec_iso_eff, *Data_TAP_elec_iso_eff, *MC_TAP_elec_reco_eff, *Data_TAP_elec_reco_eff;
// eff binning parameters
// borders for the njet bins
double NjetLowLow_=1.6;
double NjetHighLow_ = 2.6;
double NjetLow0_=2.6;
double NjetHigh0_=5.6;
double NjetLow1_=5.6;
double NjetHigh1_=7.6;
double NjetLow2_=7.6;
double NjetHigh2_=9999;
const int muIsoHTLow_=3;
double MuIsoHTLow_[muIsoHTLow_]={500,800,2000};
const int muIsoMHTLow_=7;
double MuIsoMHTLow_[muIsoMHTLow_]={0,50,100,200,450,600,2500};
const int muIsoHT0_=5;
double MuIsoHT0_[muIsoHT0_]={500,800,1000,1250,2000};
const int muIsoMHT0_=8;
double MuIsoMHT0_[muIsoMHT0_]={0,50,100,200,300,450,600,2500};
const int muIsoHT1_=6;
double MuIsoHT1_[muIsoHT1_]={500,800,1000,1250,1500,2000};
const int muIsoMHT1_=7;
double MuIsoMHT1_[muIsoMHT1_]={0,50,100,200,300,450,2500};
const int muIsoHT2_=6;
double MuIsoHT2_[muIsoHT2_]={500,800,1000,1250,1500,2000};
const int muIsoMHT2_=5;
double MuIsoMHT2_[muIsoMHT2_]={0,50,100,200,2500};

const int muRecoHTLow_=3;
double MuRecoHTLow_[muRecoHTLow_]={500,800,2000};
const int muRecoMHTLow_=7;
double MuRecoMHTLow_[muRecoMHTLow_]={0,50,100,200,450,600,2500};
const int muRecoHT0_=5;
double MuRecoHT0_[muRecoHT0_]={500,800,1000,1250,2000};
const int muRecoMHT0_=8;
double MuRecoMHT0_[muRecoMHT0_]={0,50,100,200,300,450,600,2500};
const int muRecoHT1_=6;
double MuRecoHT1_[muRecoHT1_]={500,800,1000,1250,1500,2000};
const int muRecoMHT1_=7;
double MuRecoMHT1_[muRecoMHT1_]={0,50,100,200,300,450,2500};
const int muRecoHT2_=6;
double MuRecoHT2_[muRecoHT2_]={500,800,1000,1250,1500,2000};
const int muRecoMHT2_=5;
double MuRecoMHT2_[muRecoMHT2_]={0,50,100,200,2500};


const int muAccMht_ = 7;
double MuAccMht_ [muAccMht_]={0,50,100,200,300,450,2600};
const int muAccNJets_ = 6;
double MuAccNJets_ [muAccNJets_]={2,3,4,6,7,14};

const int elecIsoHTLow_=3;
double ElecIsoHTLow_[elecIsoHTLow_]={500,800,2000};
const int elecIsoMHTLow_=7;
double ElecIsoMHTLow_[elecIsoMHTLow_]={0,100,200,300,450,600,2500};
const int elecIsoHT0_=5;
double ElecIsoHT0_[elecIsoHT0_]={500,800,1000,1250,2000};
const int elecIsoMHT0_=8;
double ElecIsoMHT0_[elecIsoMHT0_]={0,50,100,200,300,450,600,2500};
const int elecIsoHT1_=6;
double ElecIsoHT1_[elecIsoHT1_]={500,800,1000,1250,1500,2000};
const int elecIsoMHT1_=7;
double ElecIsoMHT1_[elecIsoMHT1_]={0,50,100,200,300,450,2500};
const int elecIsoHT2_=6;
double ElecIsoHT2_[elecIsoHT2_]={500,800,1000,1250,1500,2000};
const int elecIsoMHT2_=5;
double ElecIsoMHT2_[elecIsoMHT2_]={0,50,100,200,2500};

const int elecRecoHTLow_=4;
double ElecRecoHTLow_[elecRecoHTLow_]={500,800,1000,2000};
const int elecRecoMHTLow_=8;
double ElecRecoMHTLow_[elecRecoMHTLow_]={0,50,100,200,300,450,600,2500};
const int elecRecoHT0_=5;
double ElecRecoHT0_[elecRecoHT0_]={500,800,1000,1250,2000};
const int elecRecoMHT0_=8;
double ElecRecoMHT0_[elecRecoMHT0_]={0,50,100,200,300,450,600,2500};
const int elecRecoHT1_=6;
double ElecRecoHT1_[elecRecoHT1_]={500,800,1000,1250,1500,2000};
const int elecRecoMHT1_=7;
double ElecRecoMHT1_[elecRecoMHT1_]={0,50,100,200,300,450,2500};
const int elecRecoHT2_=6;
double ElecRecoHT2_[elecRecoHT2_]={500,800,1000,1250,1500,2000};
const int elecRecoMHT2_=5;
double ElecRecoMHT2_[elecRecoMHT2_]={0,50,100,200,2500};

const int elecAccMht_ = 7;
double ElecAccMht_ [elecAccMht_]={0,50,100,200,300,450,2600};
const int elecAccNJets_ = 6;
double ElecAccNJets_ [elecAccNJets_]={2,3,4,6,7,14};

const int mtwNjet_ = 5;
double MtwNjet_[mtwNjet_] ={2,3,4,5,14};

const int mtwMHT_ = 5;
double MtwMHT_[mtwMHT_] ={0,100,200,400,1200};
/*
MuIsoHT1_[20],MuIsoHT2_[20];
double* MuIsoMHT0_[20],MuIsoMHT1_[20],MuIsoMHT2_[20];

double* MuRecoHT0_[20],MuRecoHT1_[20],MuRecoHT2_[20];
double* MuRecoMHT0_[20],MuRecoMHT1_[20],MuRecoMHT2_[20];

double* MuAccMHT_[20],MuAccNJet_[20];

double* mtwnjet_[20];

std::vector<double> MuIsoMHT0_ ;
std::vector<double> MuIsoHT0_ ;
std::vector<double> MuIsoMHT1_ ;
std::vector<double> MuIsoHT1_ ;
std::vector<double> MuIsoMHT2_ ;
std::vector<double> MuIsoHT2_ ;

std::vector<double> MuRecoMHT0_ ;
std::vector<double> MuRecoHT0_ ;
std::vector<double> MuRecoMHT1_ ;
std::vector<double> MuRecoHT1_ ;
std::vector<double> MuRecoMHT2_ ;
std::vector<double> MuRecoHT2_ ;

std::vector<double> MuAccMHT_ ;
std::vector<double> MuAccNJet_ ;

//
std::vector<double> ElecIsoMHT0_ ;
std::vector<double> ElecIsoHT0_ ;
std::vector<double> ElecIsoMHT1_ ;
std::vector<double> ElecIsoHT1_ ;
std::vector<double> ElecIsoMHT2_ ;
std::vector<double> ElecIsoHT2_ ;

std::vector<double> ElecRecoMHT0_ ;
std::vector<double> ElecRecoHT0_ ;
std::vector<double> ElecRecoMHT1_ ;
std::vector<double> ElecRecoHT1_ ;
std::vector<double> ElecRecoMHT2_ ;
std::vector<double> ElecRecoHT2_ ;

std::vector<double> ElecAccMHT_ ;
std::vector<double> ElecAccNJet_ ;

//
std::vector<double> mtwnjet_ ;
*/
#endif

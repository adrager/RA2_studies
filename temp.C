#include <TH2F.h>
#include <TFile.h>
#include <TCanvas.h>
#include <iostream>

void temp()

{

TFile* fITAP = TFile::Open("tapInput/MuIsoMC.root");
TObject* test = fITAP->Get("tapTreeMuIso/MuIso_deltaR_RelPt/fit_eff_plots/MuIsoDeltaR30GeVJet_MuIsoRelPT30GeVJet_PLOT");
if(!test)std::cout<<"nope";
TCanvas* testC = (TCanvas*) test;
testC->Draw();
}


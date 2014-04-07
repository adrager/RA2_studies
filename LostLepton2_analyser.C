#include <TH2F.h>
#include <TFile.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <iostream>
#include "TStyle.h"
#include <ostream>
#include <fstream> 
#include <string.h>
#include <TTree.h>
#include <TH1.h>
#include <TH3.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TMath.h>
#include <TF1.h>
#include <stdio.h>
#include "TROOT.h"
#include "TMinuit.h"
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "Fit/Fitter.h"
#include "Fit/BinData.h"
#include "Fit/Chi2FCN.h"
#include "TH1.h"
#include "TList.h"
#include "Math/WrappedMultiTF1.h"
#include "Math/FitMethodFunction.h"
#include "HFitInterface.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TList.h"
#include "TROOT.h"

#include "EffMaker.h"
#include "RA2LostLeptonAnalyzer.h"
#include "GlobalVars.h"
#include "DataCard_Print.h"



// functions



void LostLepton2_analyser()
{
// lost lepton analyser module
//Please use root -l LostLepton2_analyser.C+ to start.
/*
This module can do the prediciton which is saved in a ttree and also determin the efficiency maps derived from MC. It is not desinged to derive the tag and probe efficiencies these must be entered as input.
Please use the switches in the beginning of the file to set the efficiency determination to use as input or to produce them. Also set if you want to do the prediction and if so how the efficiencies should be binned. Set right now to use MHT, HT, and NJet as parametirzeation values.

*/
	recomputeEff_=true;
	useSavedEff_=false;
	baselineHT_=500;
	baselineMHT_=0;
	baselineNJets_=2;
	deltaPhi1_=0.5;
	deltaPhi2_=0.5;
	deltaPhi3_=0.3;
	// lost lepton variables and cuts
	mtwCut_=100;
	DiLepCorrection_=-2; // in % of total prediciton
	DiLepCorrectionUp_=50; // in % of the Correctionfactor
	DiLepCorrectionDown_=50; // in % of the Correctionfactor
	MTWUncertaintyUp_=40; // in % on the correction factor
	MTWUncertaintyDown_=40;  // in % on trhe correction factor
	MuAccUncertaintyUp_=9; //  % of the acceptance fraction 
	MuAccUncertaintyDown_=9; // % of the acceptance fraction
	ElecAccUncertaintyUp_=9; // % of the acceptance fraction
	ElecAccUncertaintyDown_=9; // % of the acceptance fraction
	diBosonDown_=3.0; // on the total prediction
  	NonClosureLowNJet_ = 15; // in % of the total prediction
   	NonClosureHighNJet_ = 20;

	using namespace std;
	cout<<"Lost Lepton module started..."<<endl;
	// file setup
	outPutFile_ = new TFile("LostLepton.root","RECREATE");
	//outPutFile_->mkdir("LostLepton");
	//prediction_ = (TDirectory*)outPutFile_->Get("LostLeptonPrediction");
	// global settings
	debug_=true;
	filters_ = true; // set to true if filters should be applied

	//gROOT->SetBatch(true);
	gStyle->SetPaintTextFormat("5.2f");
	gStyle->SetTitleYOffset(2.2);
	gStyle->SetOptStat(0);
	if(debug_)cout<<"Debug mode activated..."<<endl;
	else cout<<"Debug deactivated-> reduced couts"<<endl;
	// determin eather the efficiencies on the fly with here definded binning or use stored efficiency maps
	//efficienciesTAP_ = TFile::Open("MCEff.root");
	// to analyse trees (data or/and mc)
	if(debug_) cout<<"Setup done... starting analysis"<<std::endl;
	cout<<"Recomputing eff..."<<endl;

	//TDirectory *muon = (TDirectory*)efficienciesTAP_->Get("Muon");
	//TDirectory *elec = (TDirectory*)efficienciesTAP_->Get("Electron");
	// get TAP muon efficiencies
	TFile* fITAP1 = TFile::Open("tapInput/MuIsoMC.root");
	MC_TAP_mu_iso_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeMuIso/MuIso_deltaR_RelPt/fit_eff_plots/MuIsoDeltaR30GeVJet_MuIsoRelPT30GeVJet_PLOT")))->GetPrimitive("MuIsoDeltaR30GeVJet_MuIsoRelPT30GeVJet_PLOT");
	MC_TAP_mu_iso_eff->SetName("MC_TAP_mu_iso_eff");
	MC_TAP_mu_iso_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Iso MC T&P eff; #Delta R; #mu p_{T} / jet p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP mu iso MC done"<<endl;
	
	fITAP1 = TFile::Open("tapInput/MuIsoData.root");
	Data_TAP_mu_iso_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeMuIso/MuIso_deltaR_RelPt/fit_eff_plots/MuIsoDeltaR30GeVJet_MuIsoRelPT30GeVJet_PLOT")))->GetPrimitive("MuIsoDeltaR30GeVJet_MuIsoRelPT30GeVJet_PLOT");
	Data_TAP_mu_iso_eff->SetName("Data_TAP_mu_iso_eff");
	Data_TAP_mu_iso_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Iso Data T&P eff; #Delta R; #mu p_{T} / jet p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP mu iso data done"<<endl;
	
	fITAP1 = TFile::Open("tapInput/MuRecoMC.root");
	MC_TAP_mu_reco_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeMuId/MuId_deltaR/fit_eff_plots/MuIdDeltaR30GeVJet_MuIdProbePt_PLOT")))->GetPrimitive("MuIdDeltaR30GeVJet_MuIdProbePt_PLOT");
	MC_TAP_mu_reco_eff->SetName("MC_TAP_mu_reco_eff");
	MC_TAP_mu_reco_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Reco MC T&P eff; #Delta R; #mu p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP mu reco MC done"<<endl;
	
	fITAP1 = TFile::Open("tapInput/MuRecoData.root");
	Data_TAP_mu_reco_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeMuId/MuId_deltaR/fit_eff_plots/MuIdDeltaR30GeVJet_MuIdProbePt_PLOT")))->GetPrimitive("MuIdDeltaR30GeVJet_MuIdProbePt_PLOT");
	Data_TAP_mu_reco_eff->SetName("Data_TAP_mu_reco_eff");
	Data_TAP_mu_reco_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Reco Data T&P eff; #Delta R; #mu p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP mu reco MC done"<<endl;
	
	fITAP1 = TFile::Open("tapInput/ElecIsoMC.root");
	MC_TAP_elec_iso_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeElecIso/ElecIso_deltaR/fit_eff_plots/ElecIsoDeltaR30GeVJet_ElecIsoProbePt_PLOT")))->GetPrimitive("ElecIsoDeltaR30GeVJet_ElecIsoProbePt_PLOT");
	MC_TAP_elec_iso_eff->SetName("MC_TAP_elec_iso_eff");
	MC_TAP_elec_iso_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #elec Iso MC T&P eff; #Delta R; elec p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP elec iso MC done"<<endl;
	
	fITAP1 = TFile::Open("tapInput/ElecIsoData.root");
	Data_TAP_elec_iso_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeElecIso/ElecIso_deltaR/fit_eff_plots/ElecIsoDeltaR30GeVJet_ElecIsoProbePt_PLOT")))->GetPrimitive("ElecIsoDeltaR30GeVJet_ElecIsoProbePt_PLOT");
	Data_TAP_elec_iso_eff->SetName("Data_TAP_elec_iso_eff");
	Data_TAP_elec_iso_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #elec Iso Data T&P eff; #Delta R; elec p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP elec iso data done"<<endl;
	
	fITAP1 = TFile::Open("tapInput/ElecRecoMC.root");
	MC_TAP_elec_reco_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeElecIdGsf/ElecIdGsf_deltaR/fit_eff_plots/ElecIdGsfDeltaR30GeVJet_ElecIdGsfProbePt_PLOT")))->GetPrimitive("ElecIdGsfDeltaR30GeVJet_ElecIdGsfProbePt_PLOT");
	MC_TAP_elec_reco_eff->SetName("MC_TAP_elec_reco_eff");
	MC_TAP_elec_reco_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #elec Reco MC T&P eff; #Delta R; elec p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP elec reco MC done"<<endl;
	
	fITAP1 = TFile::Open("tapInput/ElecRecoData.root");
	Data_TAP_elec_reco_eff = (TH2F*) ((TCanvas*)(fITAP1->Get("tapTreeElecIdGsf/ElecIdGsf_deltaR/fit_eff_plots/ElecIdGsfDeltaR30GeVJet_ElecIdGsfProbePt_PLOT")))->GetPrimitive("ElecIdGsfDeltaR30GeVJet_ElecIdGsfProbePt_PLOT");
	Data_TAP_elec_reco_eff->SetName("Data_TAP_elec_reco_eff");
	Data_TAP_elec_reco_eff->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #elec Reco Data T&P eff; #Delta R; elec p_{T};Eff");
	fITAP1->Close();
	delete fITAP1;
	cout<<"TAP elec reco data done"<<endl;
/*
	MC_TAP_mu_iso_eff = (TH2F*) muon->Get("MC_TAP_mu_iso_eff_deltaR_relPT");
	Data_TAP_mu_iso_eff = (TH2F*) muon->Get("Data_TAP_mu_iso_eff_deltaR_relPT");
	MC_TAP_mu_reco_eff = (TH2F*) muon->Get("MC_TAP_mu_reco_eff_deltaR_PT");
	Data_TAP_mu_reco_eff = (TH2F*) muon->Get("Data_TAP_mu_reco_eff_deltaR_PT");
	
	MC_TAP_elec_iso_eff = (TH2F*) elec->Get("MC_TAP_elec_iso_eff_deltaR_PT");
	Data_TAP_elec_iso_eff = (TH2F*) elec->Get("Data_TAP_elec_iso_eff_deltaR_PT");
	MC_TAP_elec_reco_eff = (TH2F*) elec->Get("MC_TAP_elec_reco_eff_deltaR_PT");
	Data_TAP_elec_reco_eff = (TH2F*) elec->Get("Data_TAP_elec_reco_eff_deltaR_PT");
*/
	TChain analyseDataChain2("RA2LostLeptonTreeMaker/RA2LostLeptonPreSelection");
	analyseDataChain2.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2mcNtuples/mc.root");
	analyseDataChain2.Process("EffMaker.C+");
	cout<<"Expectation done..."<<endl;
	predictionName_="data1Prediction";
	TChain analyseDataChain3("RA2LostLeptonTreeMaker/RA2LostLeptonPreSelection");
	analyseDataChain3.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2dataNtuples/data.root");
//	analyseDataChain.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2dataNtuples/data.root");
	cout<<"Starting data prediction"<<endl;
	analyseDataChain3.Process("RA2LostLeptonAnalyzer.C+");
	predictionName_="dataPrediction";
	TChain analyseDataChain1("RA2LostLeptonTreeMaker/RA2LostLeptonPreSelection");
	analyseDataChain1.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2dataNtuples/data.root");
//	analyseDataChain.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2dataNtuples/data.root");
	cout<<"Starting data prediction"<<endl;
	analyseDataChain1.Process("RA2LostLeptonAnalyzer.C+");
	cout<<"Starting MC prediction"<<endl;
	predictionName_="mcPrediction";
	TChain analyseDataChain4("RA2LostLeptonTreeMaker/RA2LostLeptonPreSelection");
	analyseDataChain4.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2mcNtuples/mc.root");
//	analyseDataChain.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2dataNtuples/data.root");
	analyseDataChain4.Process("RA2LostLeptonAnalyzer.C+");
	cout<<"Starting qcd prediction"<<endl;
	predictionName_="qcdPrediction";
	TChain analyseDataChain5("RA2LostLeptonTreeMaker/RA2LostLeptonPreSelection");
	analyseDataChain5.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2mcNtuples/qcd.root");
//	analyseDataChain.Add("/nfs/dust/test/cms/user/adraeger/crab/ra2/grid-control/ra2dataNtuples/data.root");
	cout<<"Starting qcd mc prediction"<<endl;
//	analyseDataChain5.Process("RA2LostLeptonAnalyzer.C+");



}

double deltaR(double eta1, double phi1, double eta2, double phi2)
{
	double deta = eta1-eta2;
	double dphi = TVector2::Phi_mpi_pi(phi1-phi2);
	return TMath::Sqrt(deta * deta + dphi *dphi); 
}
double MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi)
{
double deltaPhi =TVector2::Phi_mpi_pi(lepPhi-metPhi);
return sqrt(2*lepPt*metPt*(1-cos(deltaPhi)) );
}
double effUp(double eff, double up)
{
double result = eff + up;
if(result>0.995)result=0.995;
return result;
}

double effDown(double eff, double down)
{
double result = eff - down;
if(result<0.01)result=eff * 0.1;
return result;
}

std::pair <double,double> DRToClosestJet(UShort_t cleanPatJetsAK5CaloNum, Float_t cleanPatJetsAK5CaloPt[60], Float_t cleanPatJetsAK5CaloEta[60], Float_t cleanPatJetsAK5CaloPhi[60], Float_t lepPt, Float_t lepEta, Float_t lepPhi)
{
	double resultDR=9999;
	double resultJetPt=9999;
	// loop over all the jets in the event
	for (unsigned int i=0; i<cleanPatJetsAK5CaloNum;i++)
	{
		if(cleanPatJetsAK5CaloPt[i] <29.999) continue;
		double tempDeltaR = deltaR(cleanPatJetsAK5CaloEta[i],cleanPatJetsAK5CaloPhi[i],lepEta,lepPhi);
		if(tempDeltaR<resultDR ) // removed here && tempDeltaR>0.1 
		{
			resultDR = tempDeltaR;
			resultJetPt = cleanPatJetsAK5CaloPt[i];
		}
	}
	if(resultDR>200)
	{
		cout<<"Lep PT"<<lepPt;
		for (unsigned int i=0; i<cleanPatJetsAK5CaloNum;i++)
		{
			if(cleanPatJetsAK5CaloPt[i] <29.999) continue;
			double tempDeltaR = deltaR(cleanPatJetsAK5CaloEta[i],cleanPatJetsAK5CaloPhi[i],lepEta,lepPhi);
			cout<<" Jet"<<i<<"Pt"<<cleanPatJetsAK5CaloPt[i]<<"DeltaR"<<tempDeltaR<<", relPT"<<std::abs(lepPt - cleanPatJetsAK5CaloPt[i])/lepPt<<", ";
		}
		cout<<endl;
	}


	return std::make_pair(resultDR,resultJetPt);
}


#define RA2LostLeptonAnalyzer_cxx
// The class definition in RA2LostLeptonAnalyzer.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("RA2LostLeptonAnalyzer.C")
// Root > T->Process("RA2LostLeptonAnalyzer.C","some options")
// Root > T->Process("RA2LostLeptonAnalyzer.C+")
//

#include "RA2LostLeptonAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include "GlobalVars.h"


void RA2LostLeptonAnalyzer::Begin(TTree *tree /*tree*/)
{
	using namespace std;
	Init(tree);
	fChain->SetEventList(0);
	// create output file
	outPutFile_->cd();
//	cout<<"Prediction File input name:"<<tree->GetName()<<endl;
	tOut_ = new TTree(predictionName_,predictionName_);
	tOut_->Branch("HT",&HT,"HT/F");
	tOut_->Branch("MHT",&MHT,"MHT/F");
	tOut_->Branch("NJets",&NJets,"NJets/s");
	tOut_->Branch("Weight",&Weight,"Weight/F");
	tOut_->Branch("NVtx",&NVtx,"NVtx/s");
	tOut_->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
	tOut_->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
	tOut_->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
	tOut_->Branch("Weight", &Weight, "Weight/F");
//	tree_->Branch("MT",&MET,"MT/F");
	tOut_->Branch("patMuonsPFIDIsoNum",&patMuonsPFIDIsoNum,"patMuonsPFIDIsoNum/I");
	tOut_->Branch("patElectronsIDIsoNum",&patElectronsIDIsoNum,"patElectronsIDIsoNum/I");
	tOut_->Branch("MTW",&mtw_,"MTW/F");
	tOut_->Branch("MTWCut",&mtwCut_,"MTWCut/F");
	tOut_->Branch("deltaRLepJet",&deltaRLepJet_,"deltaRLepJet/F");
	tOut_->Branch("deltaRJetPt",&deltaRJetPt_,"deltaRJetPt/F");
	tOut_->Branch("deltaRJetPtRel",&deltaRJetPtRel_,"deltaRJetPtRel/F");
	tOut_->Branch("MuPt",&muPt_,"MuPt/F");	
	tOut_->Branch("MuEta",&muEta_,"MuEta/F");	
	tOut_->Branch("MuPhi",&muPhi_,"MuPhi/F");	
	tOut_->Branch("totalPrediction",&totalWeight_,"totalPrediction/F");
	tOut_->Branch("totalPredictionMTW",&totalWeightMTW_,"totalPredictionMTW/F");
	tOut_->Branch("totalWeightMTWDiLep",&totalWeightMTWDiLep_,"totalWeightMTWDiLep/F");
	
	tOut_->Branch("muIsoWeight",&muIsoWeight_,"muIsoWeight/F");
	tOut_->Branch("muIsoWeightErrorUp",&muIsoWeightErrorUp_,"muIsoWeightErrorUp/F");
	tOut_->Branch("muIsoWeightErrorDown",&muIsoWeightErrorDown_,"muIsoWeightErrorDown/F");
	tOut_->Branch("muRecoWeight",&muRecoWeight_,"muRecoWeight_/F");
	tOut_->Branch("muRecoWeightErrorUp",&muRecoWeightErrorUp_,"muRecoWeightErrorUp/F");
	tOut_->Branch("muRecoWeightErrorDown",&muRecoWeightErrorDown_,"muRecoWeightErrorDown/F");
	tOut_->Branch("muAccWeight",&muAccWeight_,"muAccWeight_/F");
	tOut_->Branch("muAccWeightErrorUp",&muAccWeightErrorUp_,"muAccWeightErrorUp/F");
	tOut_->Branch("muAccWeightErrorDown",&muAccWeightErrorDown_,"muAccWeightErrorDown/F");
	tOut_->Branch("muTotalWeight",&muTotalWeight_,"muTotalWeight/F");
	tOut_->Branch("muIsoEff",&muIsoEff_,"muIsoEff/F");
	tOut_->Branch("muRecoEff",&muRecoEff_,"muRecoEff/F");
	tOut_->Branch("muAccEff",&muAccEff_,"muAccEff/F");
	
	tOut_->Branch("elecIsoWeight",&elecIsoWeight_,"elecIsoWeight/F");
	tOut_->Branch("elecIsoWeightErrorUp",&elecIsoWeightErrorUp_,"elecIsoWeightErrorUp/F");
	tOut_->Branch("elecIsoWeightErrorDown",&elecIsoWeightErrorDown_,"elecIsoWeightErrorDown/F");
	tOut_->Branch("elecRecoWeight",&elecRecoWeight_,"elecRecoWeight_/F");
	tOut_->Branch("elecRecoWeightErrorUp",&elecRecoWeightErrorUp_,"elecRecoWeightErrorUp/F");
	tOut_->Branch("elecRecoWeightErrorDown",&elecRecoWeightErrorDown_,"elecRecoWeightErrorDown/F");
	tOut_->Branch("elecAccWeight",&elecAccWeight_,"elecAccWeight_/F");
	tOut_->Branch("elecAccWeightErrorUp",&elecAccWeightErrorUp_,"elecAccWeightErrorUp/F");
	tOut_->Branch("elecAccWeightErrorDown",&elecAccWeightErrorDown_,"elecAccWeightErrorDown/F");
	tOut_->Branch("elecTotalWeight",&elecTotalWeight_,"elecTotalWeight/F");
	tOut_->Branch("elecIsoEff",&elecIsoEff_,"elecIsoEff/F");
	tOut_->Branch("elecRecoEff",&elecRecoEff_,"elecRecoEff/F");
	tOut_->Branch("elecAccEff",&elecAccEff_,"elecAccEff/F");

	tOut_->Branch("totalWeightMTWDiLepUp",&totalWeightMTWDiLepUp_,"totalWeightMTWDiLepUp/F");
	tOut_->Branch("totalWeightMTWDiLepDown",&totalWeightMTWDiLepDown_,"totalWeightMTWDiLepDown/F");
	tOut_->Branch("totalWeightMTWUp",&totalWeightMTWUp_,"totalWeightMTWUp/F");
	tOut_->Branch("totalWeightMTWDown",&totalWeightMTWDown_,"totalWeightMTWDown/F");
	
	tOut_->Branch("muIsoUp",&muIsoUp_,"muIsoUp/F");
	tOut_->Branch("muIsoDown",&muIsoDown_,"muIsoDown/F");
	tOut_->Branch("muAccUp",&muAccUp_,"muAccUp/F");
	tOut_->Branch("muAccDown",&muAccDown_,"muAccDown/F");
	tOut_->Branch("elecAccUp",&elecAccUp_,"elecAccUp/F");
	tOut_->Branch("elecAccDown",&elecAccDown_,"elecAccDown/F");
	tOut_->Branch("totalWeightMTWDiLepDiBosonDown",&totalWeightMTWDiLepDiBosonDown_,"totalWeightMTWDiLepDiBosonDown/F");
	tOut_->Branch("totalWeightMTWDiLepDiNonCloUp",&totalWeightMTWDiLepDiNonCloUp_,"totalWeightMTWDiLepDiNonCloUp/F");
	tOut_->Branch("totalWeightMTWDiLepDiNonCloDown",&totalWeightMTWDiLepDiNonCloDown_,"totalWeightMTWDiLepDiNonCloDown/F");
		
	tOut_->Branch("muonIsoTAPUp",&muonIsoTAPUp_,"muonIsoTAPUp/F");
	tOut_->Branch("muonIsoTAPDown",&muonIsoTAPDown_,"muonIsoTAPDown/F");
	tOut_->Branch("muonRecoTAPUp",&muonRecoTAPUp_,"muonRecoTAPUp/F");
	tOut_->Branch("muonRecoTAPDown",&muonRecoTAPDown_,"muonRecoTAPDown/F");
	tOut_->Branch("elecIsoTAPUp",&elecIsoTAPUp_,"elecIsoTAPUp/F");
	tOut_->Branch("elecIsoTAPDown",&elecIsoTAPDown_,"elecIsoTAPDown/F");
	tOut_->Branch("elecRecoTAPUp",&elecRecoTAPUp_,"elecRecoTAPUp/F");
	tOut_->Branch("elecRecoTAPDown",&elecRecoTAPDown_,"elecRecoTAPDown/F");
		
	// % uncertainties
	tOut_->Branch("ptotalWeigthMTWCorrection_",&ptotalWeigthMTWCorrection_,"ptotalWeigthMTWCorrection_/F");
	tOut_->Branch("ptotalWeigthDiLepCorrection_",&ptotalWeigthDiLepCorrection_,"ptotalWeigthDiLepCorrection_/F");
	
	tOut_->Branch("ptotalWeightMTWDiLepUp_",&ptotalWeightMTWDiLepUp_,"ptotalWeightMTWDiLepUp_/F");
	tOut_->Branch("ptotalWeightMTWDiLepDown_",&ptotalWeightMTWDiLepDown_,"ptotalWeightMTWDiLepDown_/F");
	tOut_->Branch("ptotalWeightMTWUp_",&ptotalWeightMTWUp_,"ptotalWeightMTWUp_/F");
	tOut_->Branch("ptotalWeightMTWDown_",&ptotalWeightMTWDown_,"ptotalWeightMTWDown_/F");
	
/*	tOut_->Branch("pmuIsoUp_",&pmuIsoUp_,"pmuIsoUp_/F");
	tOut_->Branch("pmuIsoDown_",&pmuIsoDown_,"pmuIsoDown_/F"); */
	tOut_->Branch("pmuAccUp_",&pmuAccUp_,"pmuAccUp_/F");
	tOut_->Branch("pmuAccDown_",&pmuAccDown_,"pmuAccDown_/F");

	tOut_->Branch("pelecAccUp_",&pelecAccUp_,"pelecAccUp_/F");
	tOut_->Branch("pelecAccDown_",&pelecAccDown_,"pelecAccDown_/F");
	tOut_->Branch("ptotalWeightMTWDiLepDiBosonDown_",&ptotalWeightMTWDiLepDiBosonDown_,"ptotalWeightMTWDiLepDiBosonDown_/F");
	tOut_->Branch("ptotalWeightMTWDiLepDiNonCloUp_",&ptotalWeightMTWDiLepDiNonCloUp_,"ptotalWeightMTWDiLepDiNonCloUp_/F");
	tOut_->Branch("ptotalWeightMTWDiLepDiNonCloDown_",&ptotalWeightMTWDiLepDiNonCloDown_,"ptotalWeightMTWDiLepDiNonCloDown_/F");
		
	tOut_->Branch("pmuonIsoTAPUp_",&pmuonIsoTAPUp_,"pmuonIsoTAPUp_/F");
	tOut_->Branch("pmuonIsoTAPDown_",&pmuonIsoTAPDown_,"pmuonIsoTAPDown_/F");
	tOut_->Branch("pmuonRecoTAPUp_",&pmuonRecoTAPUp_,"pmuonRecoTAPUp_/F");
	tOut_->Branch("pmuonRecoTAPDown_",&pmuonRecoTAPDown_,"pmuonRecoTAPDown_/F");
	tOut_->Branch("pelecIsoTAPUp_",&pelecIsoTAPUp_,"pelecIsoTAPUp_/F");
	tOut_->Branch("pelecIsoTAPDown_",&pelecIsoTAPDown_,"pelecIsoTAPDown_/F");
	tOut_->Branch("pelecRecoTAPUp_",&pelecRecoTAPUp_,"pelecRecoTAPUp_/F");
	tOut_->Branch("pelecRecoTAPDown_",&pelecRecoTAPDown_,"pelecRecoTAPDown_/F");
	// TAP Weights for x checks
	tOut_->Branch("muonTAPIsoWeightData_",&muonTAPIsoWeightData_,"muonTAPIsoWeightData_/F");
	tOut_->Branch("muonTAPIsoWeightMC_",&muonTAPIsoWeightMC_,"muonTAPIsoWeightMC_/F");
	tOut_->Branch("muonTAPRecoWeightData_",&muonTAPRecoWeightData_,"muonTAPRecoWeightData_/F");
	tOut_->Branch("muonTAPRecoWeightMC_",&muonTAPRecoWeightMC_,"muonTAPRecoWeightMC_/F");
	
	tOut_->Branch("elecTAPIsoWeightData_",&elecTAPIsoWeightData_,"elecTAPIsoWeightData_/F");
	tOut_->Branch("elecTAPIsoWeightMC_",&elecTAPIsoWeightMC_,"elecTAPIsoWeightMC_/F");
	tOut_->Branch("elecTAPRecoWeightData_",&elecTAPRecoWeightData_,"elecTAPRecoWeightData_/F");
	tOut_->Branch("elecTAPRecoWeightMC_",&elecTAPRecoWeightMC_,"elecTAPRecoWeightMC_/F");
	

	number=0;
	events=0;
	totalPrediction_=0;
	muIsoPre_=0;
	muRecoPre_=0;
	muAccPre_=0;
	elecIsoPre_=0;
	elecRecoPre_=0;
	elecAccPre_=0;
	cout<<"Beginning prediction..."<<endl;
	
	
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void RA2LostLeptonAnalyzer::SlaveBegin(TTree *tree/*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t RA2LostLeptonAnalyzer::Process(Long64_t entry)
{
	resetValues();
	events++;
	fChain->GetTree()->GetEntry(entry);
	if(HT<baselineHT_ || MHT< baselineMHT_ || NJets+0.01 < (baselineNJets_) ||  DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_ || patMuonsPFIDIsoNum!=1 || patElectronsIDIsoNum != 0 ) return kTRUE;
	if (filters_&& (Filter_HBHENoiseFilterRA2==0 || Filter_beamHaloFilter==0 || Filter_eeNoiseFilter==0 || Filter_trackingFailureFilter==0 || Filter_inconsistentMuons == 0 || Filter_greedyMuons==0 || Filter_ra2EcalTPFilter==0 || Filter_ra2EcalBEFilter==0 || Filter_hcalLaserEventFilter==0 || Filter_ecalLaserCorrFilter==0 || Filter_eeBadScFilter ==0 || Filter_PBNRFilter==0 || Filter_HCALLaserEvtFilterList2012 ==0 || Filter_manystripclus53X==1 || Filter_toomanystripclus53X == 1 || Filter_logErrorTooManyClusters==1 || Filter_RA2HONoiseFilter ==0)) return kTRUE;
	// filter selections 
	number++;
	if(number>999)
	{
	if(debug_)cout<<"|";
	number=0;
	}
	double metpt = patMETsPFPt[0];
	double metphi = patMETsPFPhi[0];
	muPt_= patMuonsPFIDIsoPt[0];
	muEta_=patMuonsPFIDIsoEta[0];
	muPhi_=patMuonsPFIDIsoPhi[0];
	mtw_ = MTWCalculator(metpt,metphi, muPt_, muPhi_);

	deltaRLepJet_ = DRToClosestJet(cleanPatJetsAK5CaloNum, cleanPatJetsAK5CaloPt, cleanPatJetsAK5CaloEta, cleanPatJetsAK5CaloPhi, muPt_, muEta_, muPhi_).first;
	if(deltaRLepJet_>200)
	{
		cout<<"DeltaR"<<deltaRLepJet_<<", NumberOfjets"<<cleanPatJetsAK5CaloNum<<", lepPT"<<muPt_<<endl;
		for(int i=0; i < cleanPatJetsAK5CaloNum;i++)
		{
			if(cleanPatJetsAK5CaloPt[i]>30)
			{
				cout<<"Jet"<<i<<" pt:"<<cleanPatJetsAK5CaloPt[i]<<", deltaR"<<deltaR(muEta_,muPhi_, cleanPatJetsAK5CaloEta[i], cleanPatJetsAK5CaloPhi[i])<<", ";
			}
		}
		cout<<endl;
	}
	deltaRJetPt_ = DRToClosestJet(cleanPatJetsAK5CaloNum, cleanPatJetsAK5CaloPt, cleanPatJetsAK5CaloEta, cleanPatJetsAK5CaloPhi, muPt_, muEta_, muPhi_).second;
	//if(deltaRJetPt_>200) cout<<"deltaRJetPt_"<<deltaRJetPt_<<", NumberOfjets"<<cleanPatJetsAK5CaloNum<<endl;
	deltaRJetPtRel_ = muPt_ / deltaRJetPt_;


	// now do the prediction
	// obtain efficiencies
	// iso reco
	if (NJets <2.2)
	{
		muIsoEff_ = MuonIsoLow_->GetBinContent(MuonIsoLow_->GetXaxis()->FindBin(HT),MuonIsoLow_->GetYaxis()->FindBin(MHT));
		muIsoEffError_= MuonIsoLow_->GetBinError(MuonIsoLow_->GetXaxis()->FindBin(HT),MuonIsoLow_->GetYaxis()->FindBin(MHT));
		muRecoEff_ = MuonRecoLow_->GetBinContent(MuonRecoLow_->GetXaxis()->FindBin(HT),MuonRecoLow_->GetYaxis()->FindBin(MHT));
		muRecoEffError_= MuonRecoLow_->GetBinError(MuonRecoLow_->GetXaxis()->FindBin(HT),MuonRecoLow_->GetYaxis()->FindBin(MHT));
			
		elecIsoEff_ = ElecIso0_->GetBinContent(ElecIso0_->GetXaxis()->FindBin(HT),ElecIso0_->GetYaxis()->FindBin(MHT));
		elecIsoEffError_= ElecIso0_->GetBinError(ElecIso0_->GetXaxis()->FindBin(HT),ElecIso0_->GetYaxis()->FindBin(MHT));
		elecRecoEff_ = ElecReco0_->GetBinContent(ElecReco0_->GetXaxis()->FindBin(HT),ElecReco0_->GetYaxis()->FindBin(MHT));
		elecRecoEffError_= ElecReco0_->GetBinError(ElecReco0_->GetXaxis()->FindBin(HT),ElecReco0_->GetYaxis()->FindBin(MHT));
	}
	else if (NJets < 5.5 )
	{
		muIsoEff_ = MuonIso0_->GetBinContent(MuonIso0_->GetXaxis()->FindBin(HT),MuonIso0_->GetYaxis()->FindBin(MHT));
		muIsoEffError_= MuonIso0_->GetBinError(MuonIso0_->GetXaxis()->FindBin(HT),MuonIso0_->GetYaxis()->FindBin(MHT));
		muRecoEff_ = MuonReco0_->GetBinContent(MuonReco0_->GetXaxis()->FindBin(HT),MuonReco0_->GetYaxis()->FindBin(MHT));
		muRecoEffError_= MuonReco0_->GetBinError(MuonReco0_->GetXaxis()->FindBin(HT),MuonReco0_->GetYaxis()->FindBin(MHT));
			
		elecIsoEff_ = ElecIso0_->GetBinContent(ElecIso0_->GetXaxis()->FindBin(HT),ElecIso0_->GetYaxis()->FindBin(MHT));
		elecIsoEffError_= ElecIso0_->GetBinError(ElecIso0_->GetXaxis()->FindBin(HT),ElecIso0_->GetYaxis()->FindBin(MHT));
		elecRecoEff_ = ElecReco0_->GetBinContent(ElecReco0_->GetXaxis()->FindBin(HT),ElecReco0_->GetYaxis()->FindBin(MHT));
		elecRecoEffError_= ElecReco0_->GetBinError(ElecReco0_->GetXaxis()->FindBin(HT),ElecReco0_->GetYaxis()->FindBin(MHT));
		
	}
	else if (NJets < 7.5)
	{
		muIsoEff_ = MuonIso1_->GetBinContent(MuonIso1_->GetXaxis()->FindBin(HT),MuonIso1_->GetYaxis()->FindBin(MHT));
		muIsoEffError_= MuonIso1_->GetBinError(MuonIso1_->GetXaxis()->FindBin(HT),MuonIso1_->GetYaxis()->FindBin(MHT));
		muRecoEff_ = MuonReco1_->GetBinContent(MuonReco1_->GetXaxis()->FindBin(HT),MuonReco1_->GetYaxis()->FindBin(MHT));
		muRecoEffError_= MuonReco1_->GetBinError(MuonReco1_->GetXaxis()->FindBin(HT),MuonReco1_->GetYaxis()->FindBin(MHT));
			
		elecIsoEff_ = ElecIso1_->GetBinContent(ElecIso1_->GetXaxis()->FindBin(HT),ElecIso1_->GetYaxis()->FindBin(MHT));
		elecIsoEffError_= ElecIso1_->GetBinError(ElecIso1_->GetXaxis()->FindBin(HT),ElecIso1_->GetYaxis()->FindBin(MHT));
		elecRecoEff_ = ElecReco1_->GetBinContent(ElecReco1_->GetXaxis()->FindBin(HT),ElecReco1_->GetYaxis()->FindBin(MHT));
		elecRecoEffError_= ElecReco1_->GetBinError(ElecReco1_->GetXaxis()->FindBin(HT),ElecReco1_->GetYaxis()->FindBin(MHT));
	}
	else if (NJets > 7.5)
	{
		muIsoEff_ = MuonIso2_->GetBinContent(MuonIso2_->GetXaxis()->FindBin(HT),MuonIso2_->GetYaxis()->FindBin(MHT));
		muIsoEffError_= MuonIso2_->GetBinError(MuonIso2_->GetXaxis()->FindBin(HT),MuonIso2_->GetYaxis()->FindBin(MHT));
		muRecoEff_ = MuonReco2_->GetBinContent(MuonReco2_->GetXaxis()->FindBin(HT),MuonReco2_->GetYaxis()->FindBin(MHT));
		muRecoEffError_= MuonReco2_->GetBinError(MuonReco2_->GetXaxis()->FindBin(HT),MuonReco2_->GetYaxis()->FindBin(MHT));
			
		elecIsoEff_ = ElecIso2_->GetBinContent(ElecIso2_->GetXaxis()->FindBin(HT),ElecIso2_->GetYaxis()->FindBin(MHT));
		elecIsoEffError_= ElecIso2_->GetBinError(ElecIso2_->GetXaxis()->FindBin(HT),ElecIso2_->GetYaxis()->FindBin(MHT));
		elecRecoEff_ = ElecReco2_->GetBinContent(ElecReco2_->GetXaxis()->FindBin(HT),ElecReco2_->GetYaxis()->FindBin(MHT));
		elecRecoEffError_= ElecReco2_->GetBinError(ElecReco2_->GetXaxis()->FindBin(HT),ElecReco2_->GetYaxis()->FindBin(MHT));
	}
	if(muIsoEffError_ + muIsoEff_ >1.00) muIsoEffError_ = (1 - muIsoEff_)*0.5;
	if(muRecoEffError_ + muRecoEff_ >1.00) muRecoEffError_ = (1 - muRecoEff_)*0.5;
	if(elecIsoEffError_ + elecIsoEff_ >1.00) elecIsoEffError_ = (1 - elecIsoEff_)*0.5;
	if(elecRecoEffError_ + elecRecoEff_ >1.00) elecRecoEffError_ = (1 - elecRecoEff_)*0.5;
	// acceptance
	muAccEff_ = MuonAcc_->GetBinContent(MuonAcc_->GetXaxis()->FindBin(MHT),MuonAcc_->GetYaxis()->FindBin(NJets+0.01) );
	muAccEffError_ = MuonAcc_->GetBinError(MuonAcc_->GetXaxis()->FindBin(MHT),MuonAcc_->GetYaxis()->FindBin(NJets+0.01) );
	if(muAccEffError_ + muAccEff_ >1.00) muAccEffError_ = .95 - muAccEff_;
	elecAccEff_ = ElecAcc_->GetBinContent(ElecAcc_->GetXaxis()->FindBin(MHT),ElecAcc_->GetYaxis()->FindBin(NJets+0.01) );
	elecAccEffError_ = ElecAcc_->GetBinError(ElecAcc_->GetXaxis()->FindBin(MHT),ElecAcc_->GetYaxis()->FindBin(NJets+0.01) );
	if(elecAccEffError_ + elecAccEff_ >1.00) elecAccEffError_ = .95 - elecAccEff_;
	// muon iso weight & uncertainty
	muIsoWeight_ = Weight * (1 - muIsoEff_)/muIsoEff_;	
	muIsoWeightErrorUp_ = muIsoWeight_ - Weight * (1 - effUp(muIsoEff_, muIsoEffError_))/ (effUp(muIsoEff_, muIsoEffError_));
	muIsoWeightErrorDown_ = Weight * (1 - effDown(muIsoEff_, muIsoEffError_))/ (effDown(muIsoEff_, muIsoEffError_)) - muIsoWeight_;
//		cout<<"muIsoWeight_:"<<muIsoWeight_ <<"+"<<muIsoWeightErrorUp_<<"-"<<muIsoWeightErrorDown_<<endl;
	// muon reco weight & uncertainty
	muRecoWeight_ = Weight * 1 / muIsoEff_ * (1-muRecoEff_)/muRecoEff_;
	muRecoWeightErrorUp_ = muRecoWeight_ - Weight * 1 / muIsoEff_ * (1-effUp(muRecoEff_, muRecoEffError_))/(effUp(muRecoEff_, muRecoEffError_));
	muRecoWeightErrorDown_ = Weight * 1 / muIsoEff_ * (1-effDown(muRecoEff_, muRecoEffError_))/(effDown(muRecoEff_, muRecoEffError_))- muRecoWeight_;
//		cout<<"muRecoWeight_:"<<muRecoWeight_ <<"+"<<muRecoWeightErrorUp_<<"-"<<muRecoWeightErrorDown_<<endl;
	// muon acc weight & uncertainty
	muAccWeight_ = Weight * 1/muIsoEff_ * 1/muRecoEff_ *(1-muAccEff_)/muAccEff_;
	muAccWeightErrorUp_ = muAccWeight_ - Weight * 1/muIsoEff_ * 1/muRecoEff_ *(1-effUp(muAccEff_,muAccEffError_))/(effUp(muAccEff_,muAccEffError_));
	muAccUp_ = Weight * 1 / muIsoEff_ * 1/ muRecoEff_ * (1 - effUp(muAccEff_,muAccEffError_ )) / effUp(muAccEff_,muAccEffError_ );
	muAccWeightErrorDown_ = Weight * 1/muIsoEff_ * 1/muRecoEff_ *(1-effDown(muAccEff_,muAccEffError_))/(effDown(muAccEff_,muAccEffError_)) - muAccWeight_;
	muAccDown_ = Weight * 1 / muIsoEff_ * 1/ muRecoEff_ * (1 - effDown(muAccEff_,muAccEffError_ )) / effDown(muAccEff_,muAccEffError_ + muAccEff_*MuAccUncertaintyDown_ / 100);
//		cout<<"muAccWeight_:"<<muAccWeight_ <<"+"<<muAccWeightErrorUp_<<"-"<<muAccWeightErrorDown_<<endl;
	
	muTotalWeight_ = muIsoWeight_ + muRecoWeight_ + muAccWeight_;
	double totalMuons = Weight / (muIsoEff_ * muRecoEff_ * muAccEff_);
		
	// elec acc weight & uncertainty
	elecAccWeight_ = totalMuons * (1 - elecAccEff_);
	elecAccWeightErrorUp_ = elecAccWeight_ - totalMuons * (1 - effUp(elecAccEff_,elecAccEffError_));
	elecAccUp_ = totalMuons * (1- effUp(elecAccEff_, elecAccEffError_) ) ;
	elecAccWeightErrorDown_ =  totalMuons * (1 - effDown(elecAccEff_,elecAccEffError_)) - elecAccWeight_;
	elecAccDown_ = totalMuons * (1- effDown(elecAccEff_, elecAccEffError_) ) ;
//		cout<<"ElecAcc:"<<elecAccWeight_ <<"+"<<elecAccWeightErrorUp_<<"-"<<elecAccWeightErrorDown_<<endl;
	// elec reco weight & uncertainty
	elecRecoWeight_ = totalMuons * (elecAccEff_) * (1 - elecRecoEff_);
	elecRecoWeightErrorUp_ = elecRecoWeight_ - totalMuons * (elecAccEff_) * (1 - effUp(elecRecoEff_,elecRecoEffError_)) ;
	elecRecoWeightErrorDown_ =  totalMuons * (elecAccEff_) * (1 - effDown(elecRecoEff_,elecRecoEffError_)) - elecRecoWeight_;
//		cout<<"ElecReco:"<<elecRecoWeight_ <<"+"<<elecRecoWeightErrorUp_<<"-"<<elecRecoWeightErrorDown_<<endl;
	// elec iso weight & uncertainty
	elecIsoWeight_ = totalMuons * (elecAccEff_) * (elecRecoEff_) * (1 - elecIsoEff_) ;
	elecIsoWeightErrorUp_ = elecIsoWeight_ - totalMuons * (elecAccEff_) * elecRecoEff_ * (1 - effUp(elecIsoEff_,elecIsoEffError_)) ;
	elecIsoWeightErrorDown_ = totalMuons * (elecAccEff_) * elecRecoEff_ * (1 - effDown(elecIsoEff_,elecIsoEffError_)) - elecIsoWeight_;
//		cout<<"ElecIso:"<<elecIsoWeight_ <<"+"<<elecIsoWeightErrorUp_<<"-"<<elecIsoWeightErrorDown_<<endl;
	
	elecTotalWeight_ = elecAccWeight_ + elecRecoWeight_ + elecIsoWeight_;
	totalWeight_ = muTotalWeight_ + elecTotalWeight_;
	totalPrediction_+=totalWeight_;
	muIsoPre_+= muIsoWeight_;
	muRecoPre_+= muRecoWeight_;
	muAccPre_+= muAccWeight_;
	elecIsoPre_+= elecIsoWeight_;
	elecRecoPre_+= elecRecoWeight_;
	elecAccPre_+= elecAccWeight_;
	// MTW cut and uncertainty
	int MTWBinX = MTWMHTNJet_->GetXaxis()->FindBin(MHT);
	if(MTWBinX > MTWMHTNJet_->GetXaxis()->GetNbins() )
	{
		MTWBinX=MTWBinX-1;
		cout<<"MTWBinX out of range:"<<MTWMHTNJet_->GetXaxis()->GetNbins() <<", was "<<MTWMHTNJet_->GetXaxis()->FindBin(MHT)<<", set to"<<MTWBinX<<endl;
	}
	int MTWBinY = MTWMHTNJet_->GetYaxis()->FindBin(NJets+0.01);
	if(MTWBinY>MTWMHTNJet_->GetYaxis()->GetNbins() )
	{
		MTWBinY=MTWBinY-1;
		cout<<"MTWBinY out of range:"<<MTWMHTNJet_->GetYaxis()->GetNbins() <<", was "<<MTWMHTNJet_->GetYaxis()->FindBin(NJets+0.01)<<", set to"<<MTWBinY<<endl;
	}
	totalWeightMTW_ = totalWeight_ / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	ptotalWeigthMTWCorrection_ = totalWeightMTW_ / totalWeight_;
	// Di lep correction
	totalWeightMTWDiLep_= totalWeightMTW_ *(1 + DiLepCorrection_/100);
	// calculate all uncertainty weights
	// mu acc
	//muAccUp_ = (totalWeight_ - muAccWeight_ + muAccUp_ + muAccWeight_* (1 + DiLepCorrection_/100)) / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY) ;
	//muAccDown_ = (totalWeight_ - muAccWeight_ + muAccDown_ + muAccWeight_* (1 + DiLepCorrection_/100)) / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY) ;
	// elec acc
	//elecAccUp_ = (totalWeight_ - elecAccWeight_ + elecAccUp_ + elecAccWeight_ * (1 + DiLepCorrection_/100)) / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY) ;
	//elecAccDown_ = (totalWeight_ - elecAccWeight_ + elecAccDown_ + elecAccWeight_ * (1 + DiLepCorrection_/100)) / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	ptotalWeigthDiLepCorrection_ = totalWeightMTWDiLep_ / totalWeightMTW_;
	// di lep 
	totalWeightMTWDiLepUp_ = totalWeightMTW_ *(1 +  (DiLepCorrection_/100 + DiLepCorrection_ / 100 * DiLepCorrectionUp_ / 100  ) );
	ptotalWeightMTWDiLepUp_ = totalWeightMTWDiLepUp_ / totalWeightMTWDiLep_;
	totalWeightMTWDiLepDown_ = totalWeightMTW_ *(1 +  (DiLepCorrection_/100 - DiLepCorrection_ / 100 * DiLepCorrectionDown_ / 100  ) );
	ptotalWeightMTWDiLepDown_ = totalWeightMTWDiLepDown_ / totalWeightMTWDiLep_;
	// uncertainties
	// MTW
	
	double MTWeff = MTWMHTNJet_->GetBinContent(MTWBinX, MTWBinY );
	double MTWeffUp = effUp(MTWeff, MTWMHTNJet_->GetBinError(MTWBinX, MTWBinY) + (1 - MTWeff) * MTWUncertaintyUp_ / 100);
	double MTWeffDown = effDown(MTWeff, MTWMHTNJet_->GetBinError(MTWBinX, MTWBinY) + (1 - MTWeff) * MTWUncertaintyDown_ / 100);
	totalWeightMTWUp_ = totalWeight_ / (MTWeffUp);
	ptotalWeightMTWUp_ = totalWeightMTWUp_ / totalWeightMTW_;
	totalWeightMTWDown_ = totalWeight_ / (MTWeffDown);
	ptotalWeightMTWDown_ = totalWeightMTWDown_ / totalWeightMTW_;
	// acc uncertainties
	double PDFUncertainty = muAccWeight_ *MuAccUncertaintyUp_ / 100;
	PDFUncertainty = PDFUncertainty / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	double statUncertainty = std::abs(muAccUp_-muAccWeight_)/ MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	muAccUp_ = totalWeightMTWDiLep_ + PDFUncertainty + statUncertainty;
	PDFUncertainty = muAccWeight_ *MuAccUncertaintyDown_ / 100;
	PDFUncertainty = PDFUncertainty / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	statUncertainty= std::abs(muAccDown_-muAccWeight_)/ MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	muAccDown_ = totalWeightMTWDiLep_ - PDFUncertainty - statUncertainty;
	PDFUncertainty = elecAccWeight_ *ElecAccUncertaintyUp_ / 100;
	PDFUncertainty = PDFUncertainty / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	statUncertainty = std::abs(elecAccUp_-elecAccWeight_)/ MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	elecAccUp_ = totalWeightMTWDiLep_ + PDFUncertainty + statUncertainty;
	PDFUncertainty = elecAccWeight_ *ElecAccUncertaintyDown_ / 100;
	PDFUncertainty = PDFUncertainty / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	statUncertainty= std::abs(elecAccDown_-elecAccWeight_)/ MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY);
	elecAccDown_ = totalWeightMTWDiLep_ - PDFUncertainty - statUncertainty;
	// tag and probe
	// mu iso
	//mc

	int binTempX= MC_TAP_mu_iso_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> MC_TAP_mu_iso_eff->GetNbinsX()) binTempX-=1;
	if(binTempX< MC_TAP_mu_iso_eff->GetNbinsX()) binTempX+=1;
	int binTempY= MC_TAP_mu_iso_eff->GetYaxis()->FindBin(deltaRJetPtRel_);
	if(binTempY> MC_TAP_mu_iso_eff->GetNbinsY()) binTempY-=1;
	if(binTempY< MC_TAP_mu_iso_eff->GetNbinsY()) binTempY+=1;
	double mcEffTemp = MC_TAP_mu_iso_eff->GetBinContent(binTempX,binTempY);
	if(mcEffTemp>0.995) mcEffTemp=0.995;
	// data
	binTempX= Data_TAP_mu_iso_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> Data_TAP_mu_iso_eff->GetNbinsX()) binTempX-=1;
	if(binTempX< Data_TAP_mu_iso_eff->GetNbinsX()) binTempX+=1;
	binTempY= Data_TAP_mu_iso_eff->GetYaxis()->FindBin(deltaRJetPtRel_);
	if(binTempY> Data_TAP_mu_iso_eff->GetNbinsY()) binTempY-=1;
	if(binTempY< Data_TAP_mu_iso_eff->GetNbinsY()) binTempY+=1;
	double dataEffTemp = Data_TAP_mu_iso_eff->GetBinContent(binTempX,binTempY);
	if(dataEffTemp>0.995) dataEffTemp=0.995;
	if(mcEffTemp>1) cout<<"ERROR::MCTAPEFFMUISO>1:"<<mcEffTemp<<endl;
	if(dataEffTemp>1) cout<<"ERROR::DATATAPEFFMUISO>1:"<<dataEffTemp<<endl;
	// calculated realtive differnce and resulting uncertainty
	muonTAPIsoWeightMC_ = Weight * (1 - mcEffTemp)/mcEffTemp;
	muonTAPIsoWeightData_ = Weight * (1 - dataEffTemp)/dataEffTemp;
	double muonIsoTAPRelUncertainty_ = (muonTAPIsoWeightMC_-muonTAPIsoWeightData_)/muonTAPIsoWeightMC_;
	if (muonIsoTAPRelUncertainty_<-0.00) muonIsoTAPRelUncertainty_=muonIsoTAPRelUncertainty_ * (-1);
	muIsoUp_ = Weight * (1 - effUp(muIsoEff_,muIsoEffError_ + muIsoEff_ * muonIsoTAPRelUncertainty_) )/effUp(muIsoEff_,muIsoEffError_ + muIsoEff_ * muonIsoTAPRelUncertainty_);
	muIsoUp_ = (totalWeight_ - muIsoWeight_ + muIsoUp_) / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY) * (1 + DiLepCorrection_/100);
	muIsoDown_ = Weight * (1 - effDown(muIsoEff_,muIsoEffError_ + muIsoEff_ * muonIsoTAPRelUncertainty_))/effDown(muIsoEff_,muIsoEffError_ + muIsoEff_ * muonIsoTAPRelUncertainty_);
	muIsoDown_ = (totalWeight_ - muIsoWeight_ + muIsoDown_) / MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY) * (1 + DiLepCorrection_/100);
	double MuIsoFraction = muIsoWeight_/totalWeightMTWDiLep_;
	muonIsoTAPUp_ = totalWeightMTWDiLep_ + sqrt( muIsoWeight_ * muonIsoTAPRelUncertainty_ * muIsoWeight_ * muonIsoTAPRelUncertainty_ + muIsoWeightErrorUp_ * muIsoWeightErrorUp_);
	pmuonIsoTAPUp_ = muonIsoTAPUp_/ totalWeightMTWDiLep_;
	muonIsoTAPDown_ = totalWeightMTWDiLep_ - sqrt( muIsoWeight_ * muonIsoTAPRelUncertainty_ *muIsoWeight_ * muonIsoTAPRelUncertainty_ + muIsoWeightErrorDown_ * muIsoWeightErrorDown_);
	pmuonIsoTAPDown_ = muonIsoTAPDown_/ totalWeightMTWDiLep_;
	// mu reco
	binTempX= MC_TAP_mu_reco_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> MC_TAP_mu_reco_eff->GetNbinsX()) binTempX-=1;
	if(binTempX< MC_TAP_mu_reco_eff->GetNbinsX()) binTempX+=1;
	binTempY= MC_TAP_mu_reco_eff->GetYaxis()->FindBin(muPt_);
	if(binTempY> MC_TAP_mu_reco_eff->GetNbinsY()) binTempY-=1;
	if(binTempY< MC_TAP_mu_reco_eff->GetNbinsY()) binTempY+=1;
	mcEffTemp = MC_TAP_mu_reco_eff->GetBinContent(binTempX,binTempY);
	// data
	binTempX= Data_TAP_mu_reco_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> Data_TAP_mu_reco_eff->GetNbinsX()) binTempX-=1;
	if(binTempX < Data_TAP_mu_reco_eff->GetNbinsX()) binTempX+=1;
	binTempY= Data_TAP_mu_reco_eff->GetYaxis()->FindBin(muPt_);
	if(binTempY> Data_TAP_mu_reco_eff->GetNbinsY()) binTempY-=1;
	if(binTempY < Data_TAP_mu_reco_eff->GetNbinsY()) binTempY+=1;
	dataEffTemp = Data_TAP_mu_reco_eff->GetBinContent(binTempX,binTempY);
	if(mcEffTemp>1) cout<<"ERROR::MCTAPEFFMURecO>1:"<<mcEffTemp<<endl;
	if(dataEffTemp>1) cout<<"ERROR::DATATAPEFFMURecO>1:"<<dataEffTemp<<endl;
	muonTAPRecoWeightMC_ = Weight * 1 / muIsoEff_ * (1-mcEffTemp)/mcEffTemp;
	muonTAPRecoWeightData_ = Weight * 1 / muIsoEff_ * (1-dataEffTemp)/dataEffTemp;	
	double muonRecoTAPRelUncertainty = (muonTAPRecoWeightMC_-muonTAPRecoWeightData_)/muonTAPRecoWeightMC_;
	if (muonRecoTAPRelUncertainty<-0.0000001) muonRecoTAPRelUncertainty=muonRecoTAPRelUncertainty*(-1);
	double MuRecoFraction = muRecoWeight_/totalWeightMTWDiLep_;
	muonRecoTAPUp_ = totalWeightMTWDiLep_ + sqrt( muRecoWeight_ * muonRecoTAPRelUncertainty * muRecoWeight_ * muonRecoTAPRelUncertainty + muRecoWeightErrorUp_ * muRecoWeightErrorUp_ );
	pmuonRecoTAPUp_ = muonRecoTAPUp_ / totalWeightMTWDiLep_;
	muonRecoTAPDown_ = totalWeightMTWDiLep_ - sqrt( muRecoWeight_ * muonRecoTAPRelUncertainty * muRecoWeight_ * muonRecoTAPRelUncertainty + muRecoWeightErrorDown_ * muRecoWeightErrorDown_);
	pmuonRecoTAPDown_ = muonRecoTAPDown_ / totalWeightMTWDiLep_;
	if(muonRecoTAPUp_>10)cout<<"muonRecoTAPUp_"<<muonRecoTAPUp_<<", muonRecoTAPRelUncertainty"<<muonRecoTAPRelUncertainty<<", MuRecoFraction"<<MuRecoFraction<<", muRecoWeightErrorUp_"<<muRecoWeightErrorUp_<<", MCWeight"<<muonTAPRecoWeightMC_<<", DataWeight"<<muonTAPRecoWeightData_<<endl;

	// elec iso
	//mc
	binTempX= MC_TAP_elec_iso_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> MC_TAP_elec_iso_eff->GetNbinsX()) binTempX-=1;
	if(binTempX < MC_TAP_elec_iso_eff->GetNbinsX()) binTempX+=1;
	binTempY= MC_TAP_elec_iso_eff->GetYaxis()->FindBin(muPt_);
	if(binTempY> MC_TAP_elec_iso_eff->GetNbinsY()) binTempY-=1;
	if(binTempY < MC_TAP_elec_iso_eff->GetNbinsY()) binTempY+=1;
	mcEffTemp = MC_TAP_elec_iso_eff->GetBinContent(binTempX,binTempY);
	// data
	binTempX= Data_TAP_elec_iso_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> Data_TAP_elec_iso_eff->GetNbinsX()) binTempX-=1;
	if(binTempX< Data_TAP_elec_iso_eff->GetNbinsX()) binTempX+=1;
	binTempY= Data_TAP_elec_iso_eff->GetYaxis()->FindBin(muPt_);
	if(binTempY> Data_TAP_elec_iso_eff->GetNbinsY()) binTempY-=1;
	if(binTempY< Data_TAP_elec_iso_eff->GetNbinsY()) binTempY+=1;
	dataEffTemp = Data_TAP_elec_iso_eff->GetBinContent(binTempX,binTempY);
	if(mcEffTemp>1) cout<<"ERROR::MCTAPEFFMUISO>1:"<<mcEffTemp<<endl;
	if(dataEffTemp>1) cout<<"ERROR::DATATAPEFFMUISO>1:"<<dataEffTemp<<endl;
	// calculated realtive differnce and resulting uncertainty
	elecTAPIsoWeightMC_ = totalMuons * (elecAccWeight_) * (elecRecoWeight_) * (1 - mcEffTemp);
	elecTAPIsoWeightData_ = totalMuons * (elecAccWeight_) * (elecRecoWeight_) * (1 - dataEffTemp);
	double elecIsoTAPRelUncertainty_ = (elecTAPIsoWeightMC_-elecTAPIsoWeightData_)/elecTAPIsoWeightMC_;
	if (elecIsoTAPRelUncertainty_<-0.00) elecIsoTAPRelUncertainty_=elecIsoTAPRelUncertainty_ * (-1);
	double ElecIsoFraction = elecIsoWeight_/totalWeightMTWDiLep_;
	elecIsoTAPUp_ = totalWeightMTWDiLep_ + sqrt( (elecIsoWeight_ *elecIsoTAPRelUncertainty_) * (elecIsoWeight_ *elecIsoTAPRelUncertainty_)  + elecIsoWeightErrorUp_ * elecIsoWeightErrorUp_);
	pelecIsoTAPUp_ = elecIsoTAPUp_ / totalWeightMTWDiLep_;
	elecIsoTAPDown_ = totalWeightMTWDiLep_ - sqrt( (elecIsoWeight_ *elecIsoTAPRelUncertainty_) *(elecIsoWeight_ *elecIsoTAPRelUncertainty_) + elecIsoWeightErrorDown_ * elecIsoWeightErrorDown_);
	pelecIsoTAPDown_ = elecIsoTAPDown_ / totalWeightMTWDiLep_;
	// elec reco
	binTempX= MC_TAP_elec_reco_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> MC_TAP_elec_reco_eff->GetNbinsX()) binTempX-=1;
	if(binTempX < MC_TAP_elec_reco_eff->GetNbinsX()) binTempX+=1;
	binTempY= MC_TAP_elec_reco_eff->GetYaxis()->FindBin(muPt_);
	if(binTempY> MC_TAP_elec_reco_eff->GetNbinsY()) binTempY-=1;
	if(binTempY < MC_TAP_elec_reco_eff->GetNbinsY()) binTempY+=1;
	mcEffTemp = MC_TAP_elec_reco_eff->GetBinContent(binTempX,binTempY);
	// data
	binTempX= Data_TAP_elec_reco_eff->GetXaxis()->FindBin(deltaRLepJet_);
	if(binTempX> Data_TAP_elec_reco_eff->GetNbinsX()) binTempX-=1;
	if(binTempX< Data_TAP_elec_reco_eff->GetNbinsX()) binTempX+=1;
	binTempY= Data_TAP_elec_reco_eff->GetYaxis()->FindBin(muPt_);
	if(binTempY> Data_TAP_elec_reco_eff->GetNbinsY()) binTempY-=1;
	if(binTempY< Data_TAP_elec_reco_eff->GetNbinsY()) binTempY+=1;
	dataEffTemp = Data_TAP_elec_reco_eff->GetBinContent(binTempX,binTempY);
	if(mcEffTemp>1) cout<<"ERROR::MCTAPEFFMURecO>1:"<<mcEffTemp<<endl;
	if(dataEffTemp>1) cout<<"ERROR::DATATAPEFFMURecO>1:"<<dataEffTemp<<endl;
	
	elecTAPRecoWeightMC_ = totalMuons * (elecAccWeight_) * (1 - mcEffTemp);
	elecTAPRecoWeightData_ = totalMuons * (elecAccWeight_) * (1 - dataEffTemp);	
	double elecRecoTAPRelUncertainty = (elecTAPRecoWeightMC_-elecTAPRecoWeightData_)/elecTAPRecoWeightMC_;
	if (elecRecoTAPRelUncertainty<0.00) elecRecoTAPRelUncertainty=elecRecoTAPRelUncertainty*(-1);
	double ElecRecoFraction = elecRecoWeight_/totalWeightMTWDiLep_;
	elecRecoTAPUp_ = totalWeightMTWDiLep_ + sqrt( (elecRecoWeight_ *elecRecoTAPRelUncertainty) * (elecRecoWeight_ *elecRecoTAPRelUncertainty) + elecRecoWeightErrorUp_ * elecRecoWeightErrorUp_ );
	pelecRecoTAPUp_ = elecRecoTAPUp_ / totalWeightMTWDiLep_;
	elecRecoTAPDown_ = totalWeightMTWDiLep_ - sqrt( (elecRecoWeight_ *elecRecoTAPRelUncertainty) * (elecRecoWeight_ *elecRecoTAPRelUncertainty) + elecRecoWeightErrorDown_ * elecRecoWeightErrorDown_);
	pelecRecoTAPDown_ = elecRecoTAPDown_ /totalWeightMTWDiLep_;

	// acceptance error
	pmuAccUp_ = muAccUp_ / totalWeightMTWDiLep_;
	pmuAccDown_ = muAccDown_ / totalWeightMTWDiLep_;
	pelecAccUp_ = elecAccUp_ / totalWeightMTWDiLep_;
	pelecAccDown_ = elecAccDown_ / totalWeightMTWDiLep_;
	totalWeightMTWDiLepDiBosonDown_ = totalWeightMTWDiLep_ * (diBosonDown_ +100)/100;
	ptotalWeightMTWDiLepDiBosonDown_ = totalWeightMTWDiLepDiBosonDown_ / totalWeightMTWDiLep_;
	// non closure uncertainty
	if (NJets <5.5)
	{
		totalWeightMTWDiLepDiNonCloUp_= totalWeightMTWDiLep_ + totalWeightMTWDiLep_ * NonClosureLowNJet_/100;
		totalWeightMTWDiLepDiNonCloDown_= totalWeightMTWDiLep_ - totalWeightMTWDiLep_ * NonClosureLowNJet_/100;
	}
	if ( NJets>5.5)
	{
		totalWeightMTWDiLepDiNonCloUp_= totalWeightMTWDiLep_ + totalWeightMTWDiLep_ * NonClosureHighNJet_/100;
		totalWeightMTWDiLepDiNonCloDown_= totalWeightMTWDiLep_ - totalWeightMTWDiLep_ * NonClosureHighNJet_/100;

	}
	ptotalWeightMTWDiLepDiNonCloUp_= totalWeightMTWDiLepDiNonCloUp_/totalWeightMTWDiLep_;
	ptotalWeightMTWDiLepDiNonCloDown_ = totalWeightMTWDiLepDiNonCloDown_/totalWeightMTWDiLep_;
	// fill the tree
	tOut_->Fill();
	if(totalWeight_>10 || totalWeightMTW_>10 || totalWeightMTWDiLep_>10 || totalWeightMTWDiLepUp_>10 || totalWeightMTWDiLep_>10 || totalWeightMTWUp_>10 || totalWeightMTWDown_>10)
	{
		cout<<"Warning in RA2LostLeptonAnalyzer: value above 10 found event content:"<<endl;
		cout<<"HT"<<HT<<endl;
		cout<<"MHT"<<MHT<<endl;
		cout<<"NJets"<<NJets<<endl;
		cout<<"mtw_"<<mtw_<<endl;
		cout<<"muIsoEff_"<<muIsoEff_<<endl;
		cout<<"muRecoEff_"<<muRecoEff_<<endl;
		cout<<"elecIsoEff_"<<elecIsoEff_<<endl;
		cout<<"elecRecoEff_"<<elecRecoEff_<<endl;
		cout<<"muAccEff_"<<muAccEff_<<endl;
		cout<<"elecAccEff_"<<elecAccEff_<<endl;
		cout<<"muIsoWeight_"<<muIsoWeight_<<endl;
		cout<<"muRecoWeight_"<<muRecoWeight_<<endl;
		cout<<"muAccWeight_"<<muAccWeight_<<endl;
		cout<<"muTotalWeight_"<<muTotalWeight_<<endl;
		cout<<"totalMuons"<<totalMuons<<endl;
		cout<<"elecAccWeight_"<<elecAccWeight_<<endl;
		cout<<"elecRecoWeight_"<<elecRecoWeight_<<endl;	
		cout<<"elecIsoWeight_"<<elecIsoWeight_<<endl;	
		cout<<"elecTotalWeight_"<<elecTotalWeight_<<endl;	
		cout<<"totalWeight_"<<totalWeight_<<endl;	
		cout<<"totalWeightMTW_"<<totalWeightMTW_<<endl;	
		cout<<"MTWMHTNJet_Eff"<<MTWMHTNJet_->GetBinContent(MTWBinX,MTWBinY)<<endl;	
		cout<<"totalWeightMTWDiLep_"<<totalWeightMTWDiLep_<<endl;	
		cout<<"muAccUp_"<<muAccUp_<<endl;	
		cout<<"muAccDown_"<<muAccDown_<<endl;	
		cout<<"elecAccUp_"<<elecAccUp_<<endl;	
		cout<<"elecAccDown_"<<elecAccDown_<<endl;	
		cout<<"totalWeightMTWDiLepUp_"<<totalWeightMTWDiLepUp_<<endl;	
		cout<<"totalWeightMTWDiLepDown_"<<totalWeightMTWDiLepDown_<<endl;	
		cout<<"totalWeightMTWUp_"<<totalWeightMTWUp_<<endl;	
		cout<<"totalWeightMTWDown_"<<totalWeightMTWDown_<<endl;	
		cout<<"muIsoUp_"<<muIsoUp_<<endl;	
		cout<<"muIsoDown_"<<muIsoDown_<<endl;	

	}
//	if(std::abs(elecIsoTAPUp_)>10 || std::abs(elecRecoTAPUp_)>10 || std::abs(muonIsoTAPUp_)>10 || std::abs(muonRecoTAPUp_)>10 ||std::abs(elecIsoTAPDown_)>10 || std::abs(elecRecoTAPDown_)>10 || std::abs(muonIsoTAPDown_)>10 || std::abs(muonRecoTAPDown_)>10)
	
	return kTRUE;
}

void RA2LostLeptonAnalyzer::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void RA2LostLeptonAnalyzer::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
	outPutFile_->cd();
	tOut_->Write();
	delete tOut_;
	cout<<endl<<"Processed events of Prediction:"<<events<<endl;
	cout<<"TotalPredictino(NoMTW and NoDilepCorrection):"<<totalPrediction_<<endl;
	cout<<"muIsoPre_"<<muIsoPre_<<endl;
	cout<<"muRecoPre_"<<muRecoPre_<<endl;
	cout<<"muAccPre_"<<muAccPre_<<endl;
	cout<<"elecIsoPre_"<<elecIsoPre_<<endl;
	cout<<"elecRecoPre_"<<elecRecoPre_<<endl;
	cout<<"elecAccPre_"<<elecAccPre_<<endl;
	cout<<"Sum"<<muIsoPre_+muRecoPre_+muAccPre_+elecIsoPre_+elecRecoPre_+elecAccPre_<<endl;
	cout<<"done. Please come again!"<<endl;

}
void RA2LostLeptonAnalyzer::resetValues()
{
	mtw_=0;
	deltaRLepJet_=0;
	deltaRJetPt_=0;
	deltaRJetPtRel_=0;
	muIsoEff_=0;
	muIsoEffError_=0;
	muIsoWeight_=0;
	muIsoWeightErrorUp_=0;
	muIsoWeightErrorDown_=0;
	muRecoEff_=0;
	muRecoEffError_=0;
	muRecoWeight_=0;	
	muRecoWeightErrorUp_=0;
	muRecoWeightErrorDown_=0;
	muAccEff_=0;
	muAccEffError_=0;
	muAccWeight_=0;
	muAccWeightErrorUp_=0;	
	muAccWeightErrorDown_=0;	
	muTotalWeight_=0;
	
	elecIsoEff_=0;
	elecIsoEffError_=0;
	elecIsoWeight_=0;
	elecIsoWeightErrorUp_=0;
	elecIsoWeightErrorDown_=0;
	elecRecoEff_=0;
	elecRecoEffError_=0;
	elecRecoWeight_=0;	
	elecRecoWeightErrorUp_=0;
	elecRecoWeightErrorDown_=0;
	elecAccEff_=0;
	elecAccEffError_=0;
	elecAccWeight_=0;
	elecAccWeightErrorUp_=0;	
	elecAccWeightErrorDown_=0;	
	elecTotalWeight_=0;
	
	totalWeight_=0;
	totalWeightMTW_=0;
	totalWeightMTWDiLep_=0;
	
	totalWeightMTWDiLepUp_=0;
	totalWeightMTWDiLepDown_=0;
	totalWeightMTWUp_=0;
	totalWeightMTWDown_=0;
	
	muIsoUp_=0;
	muIsoDown_=0;
	muAccUp_=0;
	muAccDown_=0;
	elecAccUp_=0;
	elecAccDown_=0;
	
}

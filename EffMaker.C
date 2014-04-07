#define EffMaker_cxx
// The class definition in EffMaker.h has been generated automatically
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
// Root > T->Process("EffMaker.C")
// Root > T->Process("EffMaker.C","some options")
// Root > T->Process("EffMaker.C+")
//

#include "EffMaker.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>



void EffMaker::Begin(TTree *tree /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
	using namespace std;
	Init(tree);
	fChain->SetEventList(0);
	// setup the array for the to be stored variables


	outPutFile_->cd();
	tExpectation_ = new TTree("LostLeptonExpectation","a simple Tree with simple variables");
	tExpectation_->Branch("HT",&HT,"HT/F");
	tExpectation_->Branch("MHT",&MHT,"MHT/F");
	tExpectation_->Branch("NJets",&NJets,"NJets/s");
	tExpectation_->Branch("Weight",&Weight,"Weight/F");
	tExpectation_->Branch("NVtx",&NVtx,"NVtx/s");
	tExpectation_->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
	tExpectation_->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
	tExpectation_->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
	tExpectation_->Branch("Weight", &Weight, "Weight/F");
	
	tExpectation_->Branch("TotalPassed",&total_,"TotalPassed/s");
	tExpectation_->Branch("DiLepton",&totalDiLep_,"DiLepton/s");
	
	tExpectation_->Branch("totalMTW",&totalMTW_,"totalMTW/s");
	tExpectation_->Branch("MTW",&mtw_,"MTW/F");
	
	tExpectation_->Branch("MuIsoPassed",&muIso_,"MuIsoPassed/s");
	tExpectation_->Branch("MuRecoPassed",&muReco_,"MuRecoPassed/s");
	tExpectation_->Branch("MuAccPassed",&muAcc_,"MuAccPassed/s");
	tExpectation_->Branch("MuMTWPassed",&muMTW_,"MuMTWPassed/s");
	tExpectation_->Branch("MuTotalPassed",&muTotal_,"MuTotalPassed/s");
	tExpectation_->Branch("MuGenNum",&MuGenNum_,"MuGenNum/s");
	tExpectation_->Branch("MuGenPt",&MuGenPt_,"MuGenPt[MuGenNum]/F");
	tExpectation_->Branch("MuGenEta",&MuGenEta_,"MuGenEta[MuGenNum]/F");
	tExpectation_->Branch("MuGenPhi",&MuGenPhi_,"MuGenPhi[MuGenNum]/F");
	tExpectation_->Branch("MuIsoNum",&MuIsoNum_,"MuIsoNum/s");
	tExpectation_->Branch("MuRecoNum",&MuRecoNum_,"MuRecoNum/s");
	tExpectation_->Branch("MuRecoPt",&MuRecoPt_,"MuRecoPt[MuRecoNum]/F");
	tExpectation_->Branch("MuRecoEta",&MuRecoEta_,"MuRecoEta[MuRecoNum]/F");
	tExpectation_->Branch("MuRecoPhi",&MuRecoPhi_,"MuRecoPhi[MuRecoNum]/F");
	
	tExpectation_->Branch("ElecIsoPassed",&elecIso_,"ElecIsoPassed/s");
	tExpectation_->Branch("ElecRecoPassed",&elecReco_,"ElecRecoPassed/s");
	tExpectation_->Branch("ElecAccPassed",&elecAcc_,"ElecAccPassed/s");
	tExpectation_->Branch("ElecTotalPassed",&elecTotal_,"ElecTotalPassed/s");
	tExpectation_->Branch("ElecGenNum",&ElecGenNum_,"ElecGenNum/s");
	tExpectation_->Branch("ElecGenPt",&ElecGenPt_,"ElecGenPt[ElecGenNum]/F");
	tExpectation_->Branch("ElecGenEta",&ElecGenEta_,"ElecGenEta[ElecGenNum]/F");
	tExpectation_->Branch("ElecGenPhi",&ElecGenPhi_,"ElecGenPhi[ElecGenNum]/F");
	tExpectation_->Branch("ElecRecoNum",&ElecRecoNum_,"ElecRecoNum/s");
	tExpectation_->Branch("ElecIsoNum",&ElecIsoNum_,"ElecIsoNum/s");
	tExpectation_->Branch("ElecRecoPt",&ElecRecoPt_,"ElecGenPt[ElecRecoNum]/F");
	tExpectation_->Branch("ElecRecoEta",&ElecRecoEta_,"ElecRecoEta[ElecRecoNum]/F");
	tExpectation_->Branch("ElecRecoPhi",&ElecRecoPhi_,"ElecRecoPhi[ElecRecoNum]/F");
	gROOT->cd();
	cout<<"RA2LostLeptonAnalyzer::Begin recomputing eff...."<<endl;
	MuonIsoLow_ = new TH2F("MuonIsoNJet2Jet","MuonIsoNJet2Jet",muIsoHTLow_-1,MuIsoHTLow_,muIsoMHTLow_-1,MuIsoMHTLow_);
	MuonIsoLowFail = (TH2F*)MuonIsoLow_->Clone();
	
	MuonIso0_ = new TH2F("MuonIsoNJetLow","MuonIsoNJetLow",muIsoHT0_-1,MuIsoHT0_,muIsoMHT0_-1,MuIsoMHT0_);
	MuonIso0Fail = (TH2F*)MuonIso0_->Clone();

	MuonIso1_ = new TH2F("MuonIsoNJetMedium","MuonIsoNJetMedium",muIsoHT1_-1,MuIsoHT1_,muIsoMHT1_-1,MuIsoMHT1_);
	MuonIso1Fail = (TH2F*)MuonIso1_->Clone();
	MuonIso2_ = new TH2F("MuonIsoNJetHgih","MuonIsoNJetHigh",muIsoHT2_-1,MuIsoHT2_,muIsoMHT2_-1,MuIsoMHT2_);
	MuonIso2Fail = (TH2F*)MuonIso2_->Clone();
	
	MuonRecoLow_ = new TH2F("MuonRecoNJet2Jet","MuonRecoNJet2Jet",muRecoHTLow_-1,MuRecoHTLow_,muRecoMHTLow_-1,MuRecoMHTLow_);
	MuonRecoLowFail = (TH2F*)MuonRecoLow_->Clone();
	MuonReco0_ = new TH2F("MuonRecoNJetLow","MuonRecoNJetLow",muRecoHT0_-1,MuRecoHT0_,muRecoMHT0_-1,MuRecoMHT0_);
	MuonReco0Fail = (TH2F*)MuonReco0_->Clone();
	MuonReco1_ = new TH2F("MuonRecoNJetMedium","MuonRecoNJetMedium",muRecoHT1_-1,MuRecoHT1_,muRecoMHT1_-1,MuRecoMHT1_);
	MuonReco1Fail = (TH2F*)MuonReco1_->Clone();
	MuonReco2_ = new TH2F("MuonRecoNJetHgih","MuonRecoNJetHigh",muRecoHT2_-1,MuRecoHT2_,muRecoMHT2_-1,MuRecoMHT2_);
	MuonReco2Fail = (TH2F*)MuonReco2_->Clone();
	
	MuonAcc_ = new TH2F("MuonAcc","MuonAcc",muAccMht_-1,MuAccMht_,muAccNJets_-1,MuAccNJets_);
	MuonAccFail = (TH2F*)MuonAcc_->Clone();
	
	ElecIsoLow_ = new TH2F("ElecIsoNJet2Jet","ElecIsoNJet2Jet",elecIsoHTLow_-1,ElecIsoHTLow_,elecIsoMHTLow_-1,ElecIsoMHTLow_);
	ElecIsoLowFail = (TH2F*)ElecIsoLow_->Clone();
	ElecIso0_ = new TH2F("ElecIsoNJetLow","ElecIsoNJetLow",elecIsoHT0_-1,ElecIsoHT0_,elecIsoMHT0_-1,ElecIsoMHT0_);
	ElecIso0Fail = (TH2F*)ElecIso0_->Clone();
	ElecIso1_ = new TH2F("ElecIsoNJetMedium","ElecIsoNJetMedium",elecIsoHT1_-1,ElecIsoHT1_,elecIsoMHT1_-1,ElecIsoMHT1_);
	ElecIso1Fail = (TH2F*)ElecIso1_->Clone();
	ElecIso2_ = new TH2F("ElecIsoNJetHgih","ElecIsoNJetHigh",elecIsoHT2_-1,ElecIsoHT2_,elecIsoMHT2_-1,ElecIsoMHT2_);
	ElecIso2Fail = (TH2F*)ElecIso2_->Clone();
	
	ElecRecoLow_ = new TH2F("ElecRecoNJet2Jet","ElecRecoNJet2Jet",elecRecoHTLow_-1,ElecRecoHTLow_,elecRecoMHTLow_-1,ElecRecoMHTLow_);
	ElecRecoLowFail = (TH2F*)ElecRecoLow_->Clone();
	ElecReco0_ = new TH2F("ElecRecoNJetLow","ElecRecoNJetLow",elecRecoHT0_-1,ElecRecoHT0_,elecRecoMHT0_-1,ElecRecoMHT0_);
	ElecReco0Fail = (TH2F*)ElecReco0_->Clone();
	ElecReco1_ = new TH2F("ElecRecoNJetMedium","ElecRecoNJetMedium",elecRecoHT1_-1,ElecRecoHT1_,elecRecoMHT1_-1,ElecRecoMHT1_);
	ElecReco1Fail = (TH2F*)ElecReco1_->Clone();
	ElecReco2_ = new TH2F("ElecRecoNJetHgih","ElecRecoNJetHigh",elecRecoHT2_-1,ElecRecoHT2_,elecRecoMHT2_-1,ElecRecoMHT2_);
	ElecReco2Fail = (TH2F*)ElecReco2_->Clone();
	
	ElecAcc_ = new TH2F("ElecAcc","ElecAcc",elecAccMht_-1,ElecAccMht_,elecAccNJets_-1,ElecAccNJets_);
	ElecAccFail = (TH2F*)ElecAcc_->Clone();
	
	MTWNJet_ = new TH1F("MTW","MTW",mtwNjet_-1,MtwNjet_);
	MTWNJetFail = (TH1F*)MTWNJet_->Clone();
	
	MTWMHTNJet_ = new TH2F("MTWMHTNjet","MTWMHTNjet",mtwMHT_-1,MtwMHT_,mtwNjet_-1,MtwNjet_);
	MTWMHTNJetFail = (TH2F*)MTWMHTNJet_->Clone();
	
	MuonIso0Fail->SetName("Fail");
	MTWNJetFail->SetName("Fail");
	ElecAccFail->SetName("Fail");
	ElecReco2Fail->SetName("Fail");
	ElecReco1Fail->SetName("Fail");
	ElecReco0Fail->SetName("Fail");
	ElecIso2Fail->SetName("Fail");
	ElecIso1Fail->SetName("Fail");
	ElecIso0Fail->SetName("Fail");
	
	MuonAccFail->SetName("Fail");
	MuonReco2Fail->SetName("Fail");
	MuonReco1Fail->SetName("Fail");
	MuonReco0Fail->SetName("Fail");
	MuonIso2Fail->SetName("Fail");
	MuonIso1Fail->SetName("Fail");
	MuonIso0Fail->SetName("Fail");
	
	
   TString option = GetOption();
   events=0;
   number=0;
   totalExpectation_=0;
   muIsoExp_=0;
   muRecoExp_=0;
   muAccExp_=0;
   elecIsoExp_=0;
   elecRecoExp_=0;
   elecAccExp_=0;

}

void EffMaker::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t EffMaker::Process(Long64_t entry)
{
	events++;
	number++;
	fChain->GetTree()->GetEntry(entry);
	if(events==1000)
	{
		if(debug_)std::cout<<"|";
		events=0;
	}
	if(HT<baselineHT_ || MHT< baselineMHT_ || NJets < (baselineNJets_-0.1) ||  DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_) 
	{
		//if(debug_) cout<<"Event skipped: HT"<<HT<<",MHT"<<MHT<<", NJets"<<NJets<<endl;
		return kTRUE;
	}
	if (filters_&& (Filter_HBHENoiseFilterRA2==0 || Filter_beamHaloFilter==0 || Filter_eeNoiseFilter==0 || Filter_trackingFailureFilter==0 || Filter_inconsistentMuons == 0 || Filter_greedyMuons==0 || Filter_ra2EcalTPFilter==0 || Filter_ra2EcalBEFilter==0 || Filter_hcalLaserEventFilter==0 || Filter_ecalLaserCorrFilter==0 || Filter_eeBadScFilter ==0 || Filter_PBNRFilter==0 || Filter_HCALLaserEvtFilterList2012 ==0 || Filter_manystripclus53X==1 || Filter_toomanystripclus53X == 1 || Filter_logErrorTooManyClusters==1 || Filter_RA2HONoiseFilter ==0)) return kTRUE;
		
	resetValues();
	MuRecoNum_=patMuonsPFIDNum;
	MuIsoNum_ = patMuonsPFIDIsoNum;
	for(int ii=0; ii< patMuonsPFIDNum;ii++)
	{
		MuRecoPt_[ii]= patMuonsPFIDPt[ii];
		MuRecoPhi_[ii]= patMuonsPFIDPhi[ii];
		MuRecoEta_[ii]= patMuonsPFIDEta[ii];
	}
	MuGenNum_=GenMuNumber;
	for (int ii=0; ii< GenMuNumber;ii++)
	{
		if(muIso_==2) break;
		//if (GenMuNumber>1.1 || GenElecNumber>0.4) break;
		double genPt= (*GenMuPt)[ii];
		double genEta=(*GenMuEta)[ii];
		double genPhi=(*GenMuPhi)[ii];
		MuGenPt_[ii]= (*GenMuPt)[ii];
		MuGenPhi_[ii]= (*GenMuPhi)[ii];
		MuGenEta_[ii]= (*GenMuEta)[ii];
		if (genPt<10 || std::abs(genEta) >2.4) // true if acc failed
		{
			MuonAccFail->Fill(MHT,NJets,Weight);
			muAcc_=0;
			total_=0;
		}
		else
		{
			MuonAcc_->Fill(MHT,NJets,Weight);
			muAcc_=2;
			bool RecoNotMatched=true;
			for (int iii=0; iii<patMuonsPFIDNum;iii++)
			{
				double recoPt= patMuonsPFIDPt[iii];
				double recoEta=patMuonsPFIDEta[iii];
				double recoPhi=patMuonsPFIDPhi[iii];
				if(deltaR(genEta,genPhi,recoEta,recoPhi)<0.3 && std::abs(genPt-recoPt)/genPt <0.3) // true if reco succeded
				{
					if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonRecoLow_->Fill(HT,MHT,Weight);
					if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonReco0_->Fill(HT,MHT,Weight);
					if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonReco1_->Fill(HT,MHT,Weight);
					if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonReco2_->Fill(HT,MHT,Weight);
					muReco_=2;
					RecoNotMatched=false;
					bool IsoNotMatched=true;
					for (int iv=0; iv<patMuonsPFIDIsoNum;iv++)
					{
						double isoPt= patMuonsPFIDIsoPt[iii];
						double isoEta=patMuonsPFIDIsoEta[iii];
						double isoPhi=patMuonsPFIDIsoPhi[iii];
						if(deltaR(isoEta,isoPhi,recoEta,recoPhi)<0.1 && std::abs(isoPt-recoPt)/isoPt <0.1)
						{
							IsoNotMatched=false;
							if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonIsoLow_->Fill(HT,MHT,Weight);
							if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonIso0_->Fill(HT,MHT,Weight);
							if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonIso1_->Fill(HT,MHT,Weight);
							if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonIso2_->Fill(HT,MHT,Weight);
							muIso_=2;
							total_=2;
							// mtw here
							double metpt = patMETsPFPt[0];
							double metphi = patMETsPFPhi[0];
							mtw_ = MTWCalculator(metpt,metphi, isoPt, isoPhi);
							
						}
						
					}
					if(IsoNotMatched)
					{
						if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonIsoLowFail->Fill(HT,MHT,Weight);
						if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonIso0Fail->Fill(HT,MHT,Weight);
						if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonIso1Fail->Fill(HT,MHT,Weight);
						if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonIso2Fail->Fill(HT,MHT,Weight);
						muIso_=0;
						total_=0;
					}
				}
			}
			if(RecoNotMatched)
			{
				if( NjetLowLow_ < NJets && NJets < NjetHighLow_) MuonRecoLowFail->Fill(HT,MHT,Weight);
				if( NjetLow0_ < NJets && NJets < NjetHigh0_) MuonReco0Fail->Fill(HT,MHT,Weight);
				if( NjetLow1_ < NJets && NJets < NjetHigh1_) MuonReco1Fail->Fill(HT,MHT,Weight);
				if( NjetLow2_ < NJets && NJets < NjetHigh2_) MuonReco2Fail->Fill(HT,MHT,Weight);
				muReco_=0;
				total_=0;
			}
		}
}
	ElecRecoNum_=ra2ElectronsIDNum;
	ElecIsoNum_=patElectronsIDIsoNum;
	for(int ii=0; ii< ra2ElectronsIDNum;ii++)
	{
		ElecRecoPt_[ii]= ra2ElectronsIDPt[ii];
		ElecRecoPhi_[ii]= ra2ElectronsIDPhi[ii];
		ElecRecoEta_[ii]= ra2ElectronsIDEta[ii];
	}
	ElecGenNum_=GenElecNumber;
	for (int ii=0; ii< GenElecNumber;ii++)
	{
		if(elecIso_==2) break;
		double genPt= (*GenElecPt)[ii];
		double genEta=(*GenElecEta)[ii];
		double genPhi=(*GenElecPhi)[ii];
		ElecGenPt_[ii]= (*GenElecPt)[ii];
		ElecGenPhi_[ii]= (*GenElecPhi)[ii];
		ElecGenEta_[ii]= (*GenElecEta)[ii];
		if (genPt<10 || std::abs(genEta) >2.4) // true if acc failed
		{
			ElecAccFail->Fill(MHT,NJets,Weight);
			elecAcc_=0;
			total_=0;
		}
		else if (genPt>10 && std::abs(genEta) <2.4 )
		{
			ElecAcc_->Fill(MHT,NJets,Weight);
			elecAcc_=2;
			bool RecoNotMatched=true;
			for (int iii=0; iii<ra2ElectronsIDNum;iii++)
			{	
				double recoPt= ra2ElectronsIDPt[iii];
				double recoEta=ra2ElectronsIDEta[iii];
				double recoPhi=ra2ElectronsIDPhi[iii];
				if(deltaR(genEta,genPhi,recoEta,recoPhi)<0.1 && std::abs(genPt-recoPt)/genPt <0.3) // true if reco succeded
				{
					if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecRecoLow_->Fill(HT,MHT,Weight);
					if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecReco0_->Fill(HT,MHT,Weight);
					if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecReco1_->Fill(HT,MHT,Weight);
					if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecReco2_->Fill(HT,MHT,Weight);
					elecReco_=2;
					RecoNotMatched=false;
					bool IsoNotMatched=true;
					for (int iv=0; iv<patElectronsIDIsoNum;iv++)
					{
						double isoPt= patElectronsIDIsoPt[iii];
						double isoEta=patElectronsIDIsoEta[iii];
						double isoPhi=patElectronsIDIsoPhi[iii];
						if(deltaR(isoEta,isoPhi,recoEta,recoPhi)<0.01 && std::abs(isoPt-recoPt)/isoPt <0.1)
						{
							IsoNotMatched=false;
							if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecIsoLow_->Fill(HT,MHT,Weight);
							if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecIso0_->Fill(HT,MHT,Weight);
							if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecIso1_->Fill(HT,MHT,Weight);
							if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecIso2_->Fill(HT,MHT,Weight);
							elecIso_=2;
							total_=2;
							// mtw here
						}
						
					}
					if(IsoNotMatched)
					{
						if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecIsoLowFail->Fill(HT,MHT,Weight);
						if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecIso0Fail->Fill(HT,MHT,Weight);
						if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecIso1Fail->Fill(HT,MHT,Weight);
						if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecIso2Fail->Fill(HT,MHT,Weight);
						elecIso_=0;
						total_=0;
					}
				}
			}
			if(RecoNotMatched)
			{
				if( NjetLowLow_ < NJets && NJets < NjetHighLow_) ElecRecoLowFail->Fill(HT,MHT,Weight);
				if( NjetLow0_ < NJets && NJets < NjetHigh0_) ElecReco0Fail->Fill(HT,MHT,Weight);
				if( NjetLow1_ < NJets && NJets < NjetHigh1_) ElecReco1Fail->Fill(HT,MHT,Weight);
				if( NjetLow2_ < NJets && NJets < NjetHigh2_) ElecReco2Fail->Fill(HT,MHT,Weight);
				elecReco_=0;
				total_=0;
			}
		}
	}
	if(ElecIsoNum_==0 && muIso_==2)
	{
		if(mtw_<mtwCut_) 
		{
			MTWNJet_->Fill(NJets,Weight);
			MTWMHTNJet_->Fill(MHT,NJets,Weight);
			muMTW_=2;
		}
		else 
		{
			MTWNJetFail->Fill(NJets,Weight);
			MTWMHTNJetFail->Fill(MHT,NJets,Weight);
			muMTW_=0;
		}
	}
	if( (GenElecNumber + GenMuNumber)>1.3) totalDiLep_=1;
	else if ((GenElecNumber + GenMuNumber) < 1.3) totalDiLep_=-1;
	if (muIso_==2 || elecIso_==2) 
	{
		total_=2;
		muIso_ =1;
		muReco_ =1;
		muAcc_ =1;
		muMTW_ =1;
		muTotal_=1;
		elecIso_ =1;
		elecReco_ =1;
		elecAcc_ =1;
		elecTotal_=1;
	}
	
	if(total_==0)
	{
		totalExpectation_+=Weight;
		if(muIso_==0)muIsoExp_+=Weight;
		if(muReco_==0)muRecoExp_+=Weight;
		if(muAcc_==0)muAccExp_+=Weight;
		if(elecIso_==0)elecIsoExp_+=Weight;
		if(elecReco_==0)elecRecoExp_+=Weight;
		if(elecAcc_==0)elecAccExp_+=Weight;
	}
	if(muIso_!=2 && elecIso_!=2)
	{
		if(muReco_==0 || muIso_==0 || muAcc_==0) muTotal_=0;
		if(elecReco_==0 || elecIso_==0 || elecAcc_==0) elecTotal_=0;

	}
	else if(muIso_==1)
	{
		elecIso_=0;
		elecReco_=0;
		elecAcc_=0;
		total_=0;
	}
	else if(elecIso_==1)
	{
		muIso_=0;
		muReco_=0;
		muAcc_=0;
		total_=0;
	}
	tExpectation_->Fill();

   return kTRUE;
}

void EffMaker::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void EffMaker::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
	if(debug_) cout<<endl<<"EffMaker::Terminate..."<<endl;
	cout<<"Processed events of Eff calculater:"<<number<<endl;
	cout<<"TotalExpectation(NoMTWCut)"<<totalExpectation_<<endl;
	cout<<"muIsoExp_"<<muIsoExp_<<endl;
	cout<<"muRecoExp_"<<muRecoExp_<<endl;
	cout<<"muAccExp_"<<muAccExp_<<endl;
	cout<<"elecIsoExp_"<<elecIsoExp_<<endl;
	cout<<"elecRecoExp_"<<elecRecoExp_<<endl;
	cout<<"elecAccExp_"<<elecAccExp_<<endl;
	cout<<"Sum"<<muIsoExp_+muRecoExp_+muAccExp_+elecIsoExp_+elecRecoExp_+elecAccExp_<<endl;
	outPutFile_->cd();
	outPutFile_->mkdir("Muon");
	outPutFile_->mkdir("Electron");
	TDirectory *dMu = (TDirectory*)outPutFile_->Get("Muon");
	TDirectory *dElec = (TDirectory*)outPutFile_->Get("Electron");
	// write muon to the file
	cout<<"Folder created"<<endl;
	dMu->cd();
	MuonIsoLow_ = ratioCalculator(MuonIsoLow_,MuonIsoLowFail);
	MuonIsoLowFail->Delete("all");
	MuonIsoLow_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Iso eff 2 #leqN_{Jets} #leq3; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonIsoLow_->Write();
	MuonIso0_ = ratioCalculator(MuonIso0_,MuonIso0Fail);
	MuonIso0Fail->Delete("all");
	MuonIso0_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Iso eff 3 #leqN_{Jets} #leq5; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonIso0_->Write();
	MuonIso1_ = ratioCalculator(MuonIso1_,MuonIso1Fail);
	MuonIso1Fail->Delete("all");
	MuonIso1_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Iso eff 6 #leqN_{Jets} #leq7; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonIso1_->Write();
	MuonIso2_ = ratioCalculator(MuonIso2_,MuonIso2Fail);
	MuonIso2Fail->Delete("all");
	MuonIso2_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Iso eff 8 #leqN_{Jets}; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonIso2_->Write();
	
	MuonRecoLow_ = ratioCalculator(MuonRecoLow_,MuonRecoLowFail);
	MuonRecoLowFail->Delete("all");
	MuonRecoLow_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Reco eff 2 #leqN_{Jets} #leq3; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonRecoLow_->Write();
	MuonReco0_ = ratioCalculator(MuonReco0_,MuonReco0Fail);
	MuonReco0Fail->Delete("all");
	MuonReco0_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Reco eff 3 #leqN_{Jets} #leq5; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonReco0_->Write();
	MuonReco1_ = ratioCalculator(MuonReco1_,MuonReco1Fail);
	MuonReco1Fail->Delete("all");
	MuonReco1_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Reco eff 6 #leqN_{Jets} #leq7; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonReco1_->Write();
	MuonReco2_ = ratioCalculator(MuonReco2_,MuonReco2Fail);
	MuonReco2Fail->Delete("all");
	MuonReco2_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Reco eff 8 #leqN_{Jets}; H_{T} [GeV];#slash{H}_{T} [GeV]");
	MuonReco2_->Write();
	
	MuonAcc_ = ratioCalculator(MuonAcc_,MuonAccFail);
	MuonAccFail->Delete("all");
	MuonAcc_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu Acc eff;#slash{H}_{T} [GeV]; N_{Jets}");
	MuonAcc_->Write();
	
	MTWNJet_ = ratioCalculator(MTWNJet_,MTWNJetFail);
	MTWNJetFail->Delete("all");
	MTWNJet_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu M_{T} cut eff; N_{Jets}");
	MTWNJet_->Write();
	
	MTWMHTNJet_ = ratioCalculator(MTWMHTNJet_,MTWMHTNJetFail);
	MTWMHTNJetFail->Delete("all");
	MTWMHTNJet_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, #mu M_{T} cut eff; #slash{H}_{T} [GeV];N_{Jets}");
	MTWMHTNJet_->Write();
	cout<<"nja1";	
	MC_TAP_mu_iso_eff->Write();
	cout<<"a";
	Data_TAP_mu_iso_eff->Write();
	cout<<"b";
	MC_TAP_mu_reco_eff->Write();
	cout<<"c";
	Data_TAP_mu_reco_eff->Write();
	cout<<"nja2"<<endl;
	dElec->cd();
	ElecIsoLow_ = ratioCalculator(ElecIsoLow_,ElecIsoLowFail);
	ElecIsoLowFail->Delete("all");
	ElecIsoLow_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Iso eff 2 #leqN_{Jets} #leq3; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecIsoLow_->Write();
	ElecIso0_ = ratioCalculator(ElecIso0_,ElecIso0Fail);
	ElecIso0Fail->Delete("all");
	ElecIso0_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Iso eff 3 #leqN_{Jets} #leq5; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecIso0_->Write();
	ElecIso1_ = ratioCalculator(ElecIso1_,ElecIso1Fail);
	ElecIso1Fail->Delete("all");
	ElecIso1_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Iso eff 6 #leqN_{Jets} #leq7; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecIso1_->Write();
	ElecIso2_ = ratioCalculator(ElecIso2_,ElecIso2Fail);
	ElecIso2Fail->Delete("all");
	ElecIso2_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Iso eff 8 #leqN_{Jets}; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecIso2_->Write();
	
	ElecRecoLow_ = ratioCalculator(ElecRecoLow_,ElecRecoLowFail);
	ElecRecoLowFail->Delete("all");
	ElecRecoLow_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Reco eff 2 #leqN_{Jets} #leq3; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecRecoLow_->Write();
	ElecReco0_ = ratioCalculator(ElecReco0_,ElecReco0Fail);
	ElecReco0Fail->Delete("all");
	ElecReco0_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Reco eff 3 #leqN_{Jets} #leq5; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecReco0_->Write();
	ElecReco1_ = ratioCalculator(ElecReco1_,ElecReco1Fail);
	ElecReco1Fail->Delete("all");
	ElecReco1_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Reco eff 6 #leqN_{Jets} #leq7; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecReco1_->Write();
	ElecReco2_ = ratioCalculator(ElecReco2_,ElecReco2Fail);
	ElecReco2Fail->Delete("all");
	ElecReco2_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Reco eff 8 #leqN_{Jets}; H_{T} [GeV];#slash{H}_{T} [GeV]");
	ElecReco2_->Write();
	
	ElecAcc_ = ratioCalculator(ElecAcc_,ElecAccFail);
	ElecAccFail->Delete("all");
	ElecAcc_->SetTitle("CMS Simulation, L=19.47 fb-1, sqrt(s)=8 TeV, e Acc eff;#slash{H}_{T} [GeV]; N_{Jets}");
	ElecAcc_->Write();
	
	MC_TAP_elec_iso_eff->Write();
	Data_TAP_elec_iso_eff->Write();
	MC_TAP_elec_reco_eff->Write();
	Data_TAP_elec_reco_eff->Write();
	
	cout<<"nja"<<endl;
//	fEffOut->Write();
	outPutFile_->cd();
	tExpectation_->Write();
	if(debug_)cout<<"Done. Exiting Effmaker"<<endl;

}
TH2F* ratioCalculator(TH2F* passTH2, TH2F* failTH2)
{
	passTH2->Sumw2();
	TH2F *sum = (TH2F*)passTH2->Clone();
	failTH2->Sumw2();

	sum->Add(failTH2);
	passTH2->Divide(passTH2,sum,1,1,"B");
	return passTH2;
}

TH1F* ratioCalculator(TH1F* passTH1, TH1F* failTH1)
{
	passTH1->Sumw2();
	TH1F *sum = (TH1F*)passTH1->Clone();
	failTH1->Sumw2();

	sum->Add(failTH1);
	passTH1->Divide(passTH1,sum,1,1,"B");
	return passTH1;
}

void EffMaker::resetValues()
{
	total_=1;
	totalDiLep_=1;
	totalMTW_=1;
	muIso_ =1;
	muReco_ =1;
	muAcc_ =1;
	muMTW_ =1;
	muTotal_=1;
	elecIso_ =1;
	elecReco_ =1;
	elecAcc_ =1;
	elecTotal_=1;
	MuGenNum_=0;
	ElecGenNum_=0;
	ElecIsoNum_=0;
	MuIsoNum_=0;
	MuRecoNum_=0;
	ElecRecoNum_=0;
	for (unsigned int i=0; i < 20; i++ )
	{
		MuGenPt_[i]=0.;
		MuGenPhi_[i]=0.;
		MuGenEta_[i]=0.;
		MuRecoPt_[i]=0.;
		MuRecoPhi_[i]=0.;
		MuRecoEta_[i]=0.;
		ElecGenPt_[i]=0.;
		ElecGenPhi_[i]=0.;
		ElecGenEta_[i]=0.;
		ElecRecoPt_[i]=0.;
		ElecRecoPhi_[i]=0.;
		ElecRecoEta_[i]=0.;
	}
}


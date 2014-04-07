//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 11 11:30:25 2013 by ROOT version 5.32/00
// from TTree RA2LostLeptonPreSelection/RA2LostLeptonPreSelection
// found on file: RA2LostLeptonSelection.root
//////////////////////////////////////////////////////////

#ifndef RA2LostLeptonAnalyzer_h
#define RA2LostLeptonAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class RA2LostLeptonAnalyzer : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   TTree* tOut_;

   // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   UInt_t          EvtNum;
   UShort_t        NVtx;
   Float_t         HT;
   Float_t         MHT;
   UShort_t        NJets;
   Float_t         Jet1Pt;
   Float_t         Jet2Pt;
   Float_t         Jet3Pt;
   Float_t         Jet1Eta;
   Float_t         Jet2Eta;
   Float_t         Jet3Eta;
   Float_t         DeltaPhi1;
   Float_t         DeltaPhi2;
   Float_t         DeltaPhi3;
   Float_t         Weight;
   UChar_t         Filter_HBHENoiseFilterRA2;
   UChar_t         Filter_beamHaloFilter;
   UChar_t         Filter_eeNoiseFilter;
   UChar_t         Filter_trackingFailureFilter;
   UChar_t         Filter_inconsistentMuons;
   UChar_t         Filter_greedyMuons;
   UChar_t         Filter_ra2EcalTPFilter;
   UChar_t         Filter_ra2EcalBEFilter;
   UChar_t         Filter_hcalLaserEventFilter;
   UChar_t         Filter_ecalLaserCorrFilter;
   UChar_t         Filter_eeBadScFilter;
   UChar_t         Filter_PBNRFilter;
   UChar_t         Filter_HCALLaserEvtFilterList2012;
   UChar_t         Filter_manystripclus53X;
   UChar_t         Filter_toomanystripclus53X;
   UChar_t         Filter_logErrorTooManyClusters;
   UChar_t         Filter_RA2HONoiseFilter;
   UShort_t        patMETsPFNum;
   Float_t         patMETsPFPt[1];   //[patMETsPFNum]
   Float_t         patMETsPFEta[1];   //[patMETsPFNum]
   Float_t         patMETsPFPhi[1];   //[patMETsPFNum]
   Float_t         patMETsPFE[1];   //[patMETsPFNum]
   UShort_t        cleanPatJetsAK5CaloNum;
   Float_t         cleanPatJetsAK5CaloPt[60];   //[cleanPatJetsAK5CaloNum]
   Float_t         cleanPatJetsAK5CaloEta[60];   //[cleanPatJetsAK5CaloNum]
   Float_t         cleanPatJetsAK5CaloPhi[60];   //[cleanPatJetsAK5CaloNum]
   Float_t         cleanPatJetsAK5CaloE[60];   //[cleanPatJetsAK5CaloNum]
   UShort_t        HTJetsNum;
   Float_t         HTJetsPt[28];   //[HTJetsNum]
   Float_t         HTJetsEta[28];   //[HTJetsNum]
   Float_t         HTJetsPhi[28];   //[HTJetsNum]
   Float_t         HTJetsE[28];   //[HTJetsNum]
   UShort_t        MHTJetsNum;
   Float_t         MHTJetsPt[28];   //[MHTJetsNum]
   Float_t         MHTJetsEta[28];   //[MHTJetsNum]
   Float_t         MHTJetsPhi[28];   //[MHTJetsNum]
   Float_t         MHTJetsE[28];   //[MHTJetsNum]
   UShort_t        patMuonsPFIDNum;
   Float_t         patMuonsPFIDPt[22];   //[patMuonsPFIDNum]
   Float_t         patMuonsPFIDEta[22];   //[patMuonsPFIDNum]
   Float_t         patMuonsPFIDPhi[22];   //[patMuonsPFIDNum]
   Float_t         patMuonsPFIDE[22];   //[patMuonsPFIDNum]
   UShort_t        patMuonsPFIDIsoNum;
   Float_t         patMuonsPFIDIsoPt[21];   //[patMuonsPFIDIsoNum]
   Float_t         patMuonsPFIDIsoEta[21];   //[patMuonsPFIDIsoNum]
   Float_t         patMuonsPFIDIsoPhi[21];   //[patMuonsPFIDIsoNum]
   Float_t         patMuonsPFIDIsoE[21];   //[patMuonsPFIDIsoNum]
   UShort_t        ra2ElectronsIDNum;
   Float_t         ra2ElectronsIDPt[22];   //[patElectronsIDNum]
   Float_t         ra2ElectronsIDEta[22];   //[patElectronsIDNum]
   Float_t         ra2ElectronsIDPhi[22];   //[patElectronsIDNum]
   Float_t         ra2ElectronsIDE[22];   //[patElectronsIDNum]
   UShort_t        patElectronsIDIsoNum;
   Float_t         patElectronsIDIsoPt[22];   //[patElectronsIDIsoNum]
   Float_t         patElectronsIDIsoEta[22];   //[patElectronsIDIsoNum]
   Float_t         patElectronsIDIsoPhi[22];   //[patElectronsIDIsoNum]
   Float_t         patElectronsIDIsoE[22];   //[patElectronsIDIsoNum]
/*   UShort_t        MC;
   UShort_t        GenMuNumber;
   std::vector<unsigned short> *GenMuPromt;
   std::vector<unsigned short> *GenMuTauDecay;
   std::vector<float>   *GenMuPt;
   std::vector<float>   *GenMuEta;
   std::vector<float>   *GenMuPhi;
   UShort_t        GenElecNumber;
   std::vector<unsigned short> *GenElecPromt;
   std::vector<unsigned short> *GenElecTauDecay;
   std::vector<float>   *GenElecPt;
   std::vector<float>   *GenElecEta;
   std::vector<float>   *GenElecPhi;
*/
	// addition varaibles
   Float_t muPt_, muEta_, muPhi_;
   Float_t mtw_, deltaRLepJet_, deltaRJetPt_, deltaRJetPtRel_;
   Float_t muIsoEff_, muIsoEffError_, muIsoWeight_, muIsoWeightErrorUp_, muIsoWeightErrorDown_;
   Float_t muRecoEff_, muRecoEffError_, muRecoWeight_, muRecoWeightErrorUp_, muRecoWeightErrorDown_;
   Float_t muAccEff_, muAccEffError_, muAccWeight_, muAccWeightErrorUp_, muAccWeightErrorDown_;
   Float_t muTotalWeight_;

   Float_t elecIsoEff_, elecIsoEffError_, elecIsoWeight_, elecIsoWeightErrorUp_, elecIsoWeightErrorDown_;
   Float_t elecRecoEff_, elecRecoEffError_, elecRecoWeight_, elecRecoWeightErrorUp_, elecRecoWeightErrorDown_;
   Float_t elecAccEff_, elecAccEffError_, elecAccWeight_, elecAccWeightErrorUp_, elecAccWeightErrorDown_;
   Float_t elecTotalWeight_;

   Float_t totalWeight_, totalWeightMTW_, totalWeightMTWDiLep_;
   Float_t totalWeightMTWDiLepUp_, totalWeightMTWDiLepDown_;
   Float_t totalWeightMTWUp_, totalWeightMTWDown_;
   Float_t muIsoUp_, muIsoDown_, muAccUp_, muAccDown_, elecAccUp_, elecAccDown_, totalWeightMTWDiLepDiBosonDown_, totalWeightMTWDiLepDiNonCloUp_, totalWeightMTWDiLepDiNonCloDown_;
   Float_t muonIsoTAPUp_, muonIsoTAPDown_, muonRecoTAPUp_, muonRecoTAPDown_;
   Float_t elecIsoTAPUp_, elecIsoTAPDown_, elecRecoTAPUp_, elecRecoTAPDown_;
   int number, events;
   Float_t totalPrediction_, muIsoPre_, muRecoPre_, muAccPre_, elecIsoPre_, elecRecoPre_, elecAccPre_;

   // % of total prediciton errors
   Float_t ptotalWeigthMTWCorrection_, ptotalWeigthDiLepCorrection_;
   Float_t ptotalWeightMTWDiLepUp_, ptotalWeightMTWDiLepDown_;
   Float_t ptotalWeightMTWUp_, ptotalWeightMTWDown_;
   Float_t pmuIsoUp_, pmuIsoDown_, pmuAccUp_, pmuAccDown_, pelecAccUp_, pelecAccDown_, ptotalWeightMTWDiLepDiBosonDown_, ptotalWeightMTWDiLepDiNonCloUp_, ptotalWeightMTWDiLepDiNonCloDown_;
   Float_t pmuonIsoTAPUp_, pmuonIsoTAPDown_, pmuonRecoTAPUp_, pmuonRecoTAPDown_;
   Float_t pelecIsoTAPUp_, pelecIsoTAPDown_, pelecRecoTAPUp_, pelecRecoTAPDown_;
   Float_t muonTAPRecoWeightData_, muonTAPRecoWeightMC_, muonTAPIsoWeightData_, muonTAPIsoWeightMC_;
   Float_t elecTAPRecoWeightData_, elecTAPRecoWeightMC_, elecTAPIsoWeightData_, elecTAPIsoWeightMC_;

   // List of branches
   TBranch        *b_RunNum;   //!
   TBranch        *b_LumiBlockNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_Jet1Pt;   //!
   TBranch        *b_Jet2Pt;   //!
   TBranch        *b_Jet3Pt;   //!
   TBranch        *b_Jet1Eta;   //!
   TBranch        *b_Jet2Eta;   //!
   TBranch        *b_Jet3Eta;   //!
   TBranch        *b_DeltaPhi1;   //!
   TBranch        *b_DeltaPhi2;   //!
   TBranch        *b_DeltaPhi3;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_Filter_HBHENoiseFilterRA2;   //!
   TBranch        *b_Filter_beamHaloFilter;   //!
   TBranch        *b_Filter_eeNoiseFilter;   //!
   TBranch        *b_Filter_trackingFailureFilter;   //!
   TBranch        *b_Filter_inconsistentMuons;   //!
   TBranch        *b_Filter_greedyMuons;   //!
   TBranch        *b_Filter_ra2EcalTPFilter;   //!
   TBranch        *b_Filter_ra2EcalBEFilter;   //!
   TBranch        *b_Filter_hcalLaserEventFilter;   //!
   TBranch        *b_Filter_ecalLaserCorrFilter;   //!
   TBranch        *b_Filter_eeBadScFilter;   //!
   TBranch        *b_Filter_PBNRFilter;   //!
   TBranch        *b_Filter_HCALLaserEvtFilterList2012;   //!
   TBranch        *b_Filter_manystripclus53X;   //!
   TBranch        *b_Filter_toomanystripclus53X;   //!
   TBranch        *b_Filter_logErrorTooManyClusters;   //!
   TBranch        *b_Filter_RA2HONoiseFilter;   //!
   TBranch        *b_patMETsPFNum;   //!
   TBranch        *b_patMETsPFPt;   //!
   TBranch        *b_patMETsPFEta;   //!
   TBranch        *b_patMETsPFPhi;   //!
   TBranch        *b_patMETsPFE;   //!
   TBranch        *b_cleanPatJetsAK5CaloNum;   //!
   TBranch        *b_cleanPatJetsAK5CaloPt;   //!
   TBranch        *b_cleanPatJetsAK5CaloEta;   //!
   TBranch        *b_cleanPatJetsAK5CaloPhi;   //!
   TBranch        *b_cleanPatJetsAK5CaloE;   //!
   TBranch        *b_HTJetsNum;   //!
   TBranch        *b_HTJetsPt;   //!
   TBranch        *b_HTJetsEta;   //!
   TBranch        *b_HTJetsPhi;   //!
   TBranch        *b_HTJetsE;   //!
   TBranch        *b_MHTJetsNum;   //!
   TBranch        *b_MHTJetsPt;   //!
   TBranch        *b_MHTJetsEta;   //!
   TBranch        *b_MHTJetsPhi;   //!
   TBranch        *b_MHTJetsE;   //!
   TBranch        *b_patMuonsPFIDNum;   //!
   TBranch        *b_patMuonsPFIDPt;   //!
   TBranch        *b_patMuonsPFIDEta;   //!
   TBranch        *b_patMuonsPFIDPhi;   //!
   TBranch        *b_patMuonsPFIDE;   //!
   TBranch        *b_patMuonsPFIDIsoNum;   //!
   TBranch        *b_patMuonsPFIDIsoPt;   //!
   TBranch        *b_patMuonsPFIDIsoEta;   //!
   TBranch        *b_patMuonsPFIDIsoPhi;   //!
   TBranch        *b_patMuonsPFIDIsoE;   //!
   TBranch        *b_ra2ElectronsIDNum;   //!
   TBranch        *b_ra2ElectronsIDPt;   //!
   TBranch        *b_ra2ElectronsIDEta;   //!
   TBranch        *b_ra2ElectronsIDPhi;   //!
   TBranch        *b_ra2ElectronsIDE;   //!
   TBranch        *b_patElectronsIDIsoNum;   //!
   TBranch        *b_patElectronsIDIsoPt;   //!
   TBranch        *b_patElectronsIDIsoEta;   //!
   TBranch        *b_patElectronsIDIsoPhi;   //!
   TBranch        *b_patElectronsIDIsoE;   //!
/*   TBranch        *b_MC;   //!
   TBranch        *b_GenMuNumber;   //!
   TBranch        *b_GenMuPromt;   //!
   TBranch        *b_GenMuTauDecay;   //!
   TBranch        *b_GenMuPt;   //!
   TBranch        *b_GenMuEta;   //!
   TBranch        *b_GenMuPhi;   //!
   TBranch        *b_GenElecNumber;   //!
   TBranch        *b_GenElecPromt;   //!
   TBranch        *b_GenElecTauDecay;   //!
   TBranch        *b_GenElecPt;   //!
   TBranch        *b_GenElecEta;   //!
   TBranch        *b_GenElecPhi;   //!
*/
   RA2LostLeptonAnalyzer(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~RA2LostLeptonAnalyzer() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   void resetValues();


   

   ClassDef(RA2LostLeptonAnalyzer,0);

};

#endif

#ifdef RA2LostLeptonAnalyzer_cxx
void RA2LostLeptonAnalyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
 /*  GenMuPromt = 0;
   GenMuTauDecay = 0;
   GenMuPt = 0;
   GenMuEta = 0;
   GenMuPhi = 0;
   GenElecPromt = 0;
   GenElecTauDecay = 0;
   GenElecPt = 0;
   GenElecEta = 0;
   GenElecPhi = 0;
*/
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("Jet1Pt", &Jet1Pt, &b_Jet1Pt);
   fChain->SetBranchAddress("Jet2Pt", &Jet2Pt, &b_Jet2Pt);
   fChain->SetBranchAddress("Jet3Pt", &Jet3Pt, &b_Jet3Pt);
   fChain->SetBranchAddress("Jet1Eta", &Jet1Eta, &b_Jet1Eta);
   fChain->SetBranchAddress("Jet2Eta", &Jet2Eta, &b_Jet2Eta);
   fChain->SetBranchAddress("Jet3Eta", &Jet3Eta, &b_Jet3Eta);
   fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
   fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
   fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("Filter_HBHENoiseFilterRA2", &Filter_HBHENoiseFilterRA2, &b_Filter_HBHENoiseFilterRA2);
   fChain->SetBranchAddress("Filter_beamHaloFilter", &Filter_beamHaloFilter, &b_Filter_beamHaloFilter);
   fChain->SetBranchAddress("Filter_eeNoiseFilter", &Filter_eeNoiseFilter, &b_Filter_eeNoiseFilter);
   fChain->SetBranchAddress("Filter_trackingFailureFilter", &Filter_trackingFailureFilter, &b_Filter_trackingFailureFilter);
   fChain->SetBranchAddress("Filter_inconsistentMuons", &Filter_inconsistentMuons, &b_Filter_inconsistentMuons);
   fChain->SetBranchAddress("Filter_greedyMuons", &Filter_greedyMuons, &b_Filter_greedyMuons);
   fChain->SetBranchAddress("Filter_ra2EcalTPFilter", &Filter_ra2EcalTPFilter, &b_Filter_ra2EcalTPFilter);
   fChain->SetBranchAddress("Filter_ra2EcalBEFilter", &Filter_ra2EcalBEFilter, &b_Filter_ra2EcalBEFilter);
   fChain->SetBranchAddress("Filter_hcalLaserEventFilter", &Filter_hcalLaserEventFilter, &b_Filter_hcalLaserEventFilter);
   fChain->SetBranchAddress("Filter_ecalLaserCorrFilter", &Filter_ecalLaserCorrFilter, &b_Filter_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Filter_eeBadScFilter", &Filter_eeBadScFilter, &b_Filter_eeBadScFilter);
   fChain->SetBranchAddress("Filter_PBNRFilter", &Filter_PBNRFilter, &b_Filter_PBNRFilter);
   fChain->SetBranchAddress("Filter_HCALLaserEvtFilterList2012", &Filter_HCALLaserEvtFilterList2012, &b_Filter_HCALLaserEvtFilterList2012);
   fChain->SetBranchAddress("Filter_manystripclus53X", &Filter_manystripclus53X, &b_Filter_manystripclus53X);
   fChain->SetBranchAddress("Filter_toomanystripclus53X", &Filter_toomanystripclus53X, &b_Filter_toomanystripclus53X);
   fChain->SetBranchAddress("Filter_logErrorTooManyClusters", &Filter_logErrorTooManyClusters, &b_Filter_logErrorTooManyClusters);
   fChain->SetBranchAddress("Filter_RA2HONoiseFilter", &Filter_RA2HONoiseFilter, &b_Filter_RA2HONoiseFilter);
   fChain->SetBranchAddress("patMETsPFNum", &patMETsPFNum, &b_patMETsPFNum);
   fChain->SetBranchAddress("patMETsPFPt", patMETsPFPt, &b_patMETsPFPt);
   fChain->SetBranchAddress("patMETsPFEta", patMETsPFEta, &b_patMETsPFEta);
   fChain->SetBranchAddress("patMETsPFPhi", patMETsPFPhi, &b_patMETsPFPhi);
   fChain->SetBranchAddress("patMETsPFE", patMETsPFE, &b_patMETsPFE);
   fChain->SetBranchAddress("cleanPatJetsAK5CaloNum", &cleanPatJetsAK5CaloNum, &b_cleanPatJetsAK5CaloNum);
   fChain->SetBranchAddress("cleanPatJetsAK5CaloPt", cleanPatJetsAK5CaloPt, &b_cleanPatJetsAK5CaloPt);
   fChain->SetBranchAddress("cleanPatJetsAK5CaloEta", cleanPatJetsAK5CaloEta, &b_cleanPatJetsAK5CaloEta);
   fChain->SetBranchAddress("cleanPatJetsAK5CaloPhi", cleanPatJetsAK5CaloPhi, &b_cleanPatJetsAK5CaloPhi);
   fChain->SetBranchAddress("cleanPatJetsAK5CaloE", cleanPatJetsAK5CaloE, &b_cleanPatJetsAK5CaloE);
   fChain->SetBranchAddress("HTJetsNum", &HTJetsNum, &b_HTJetsNum);
   fChain->SetBranchAddress("HTJetsPt", HTJetsPt, &b_HTJetsPt);
   fChain->SetBranchAddress("HTJetsEta", HTJetsEta, &b_HTJetsEta);
   fChain->SetBranchAddress("HTJetsPhi", HTJetsPhi, &b_HTJetsPhi);
   fChain->SetBranchAddress("HTJetsE", HTJetsE, &b_HTJetsE);
   fChain->SetBranchAddress("MHTJetsNum", &MHTJetsNum, &b_MHTJetsNum);
   fChain->SetBranchAddress("MHTJetsPt", MHTJetsPt, &b_MHTJetsPt);
   fChain->SetBranchAddress("MHTJetsEta", MHTJetsEta, &b_MHTJetsEta);
   fChain->SetBranchAddress("MHTJetsPhi", MHTJetsPhi, &b_MHTJetsPhi);
   fChain->SetBranchAddress("MHTJetsE", MHTJetsE, &b_MHTJetsE);
   fChain->SetBranchAddress("patMuonsPFIDNum", &patMuonsPFIDNum, &b_patMuonsPFIDNum);
   fChain->SetBranchAddress("patMuonsPFIDPt", patMuonsPFIDPt, &b_patMuonsPFIDPt);
   fChain->SetBranchAddress("patMuonsPFIDEta", patMuonsPFIDEta, &b_patMuonsPFIDEta);
   fChain->SetBranchAddress("patMuonsPFIDPhi", patMuonsPFIDPhi, &b_patMuonsPFIDPhi);
   fChain->SetBranchAddress("patMuonsPFIDE", patMuonsPFIDE, &b_patMuonsPFIDE);
   fChain->SetBranchAddress("patMuonsPFIDIsoNum", &patMuonsPFIDIsoNum, &b_patMuonsPFIDIsoNum);
   fChain->SetBranchAddress("patMuonsPFIDIsoPt", patMuonsPFIDIsoPt, &b_patMuonsPFIDIsoPt);
   fChain->SetBranchAddress("patMuonsPFIDIsoEta", patMuonsPFIDIsoEta, &b_patMuonsPFIDIsoEta);
   fChain->SetBranchAddress("patMuonsPFIDIsoPhi", patMuonsPFIDIsoPhi, &b_patMuonsPFIDIsoPhi);
   fChain->SetBranchAddress("patMuonsPFIDIsoE", patMuonsPFIDIsoE, &b_patMuonsPFIDIsoE);
   fChain->SetBranchAddress("ra2ElectronsIDNum", &ra2ElectronsIDNum, &b_ra2ElectronsIDNum);
   fChain->SetBranchAddress("ra2ElectronsIDPt", ra2ElectronsIDPt, &b_ra2ElectronsIDPt);
   fChain->SetBranchAddress("ra2ElectronsIDEta", ra2ElectronsIDEta, &b_ra2ElectronsIDEta);
   fChain->SetBranchAddress("ra2ElectronsIDPhi", ra2ElectronsIDPhi, &b_ra2ElectronsIDPhi);
   fChain->SetBranchAddress("ra2ElectronsIDE", ra2ElectronsIDE, &b_ra2ElectronsIDE);
   fChain->SetBranchAddress("patElectronsIDIsoNum", &patElectronsIDIsoNum, &b_patElectronsIDIsoNum);
   fChain->SetBranchAddress("patElectronsIDIsoPt", patElectronsIDIsoPt, &b_patElectronsIDIsoPt);
   fChain->SetBranchAddress("patElectronsIDIsoEta", patElectronsIDIsoEta, &b_patElectronsIDIsoEta);
   fChain->SetBranchAddress("patElectronsIDIsoPhi", patElectronsIDIsoPhi, &b_patElectronsIDIsoPhi);
   fChain->SetBranchAddress("patElectronsIDIsoE", patElectronsIDIsoE, &b_patElectronsIDIsoE);
/*   fChain->SetBranchAddress("MC", &MC, &b_MC);
   fChain->SetBranchAddress("GenMuNumber", &GenMuNumber, &b_GenMuNumber);
   fChain->SetBranchAddress("GenMuPromt", &GenMuPromt, &b_GenMuPromt);
   fChain->SetBranchAddress("GenMuTauDecay", &GenMuTauDecay, &b_GenMuTauDecay);
   fChain->SetBranchAddress("GenMuPt", &GenMuPt, &b_GenMuPt);
   fChain->SetBranchAddress("GenMuEta", &GenMuEta, &b_GenMuEta);
   fChain->SetBranchAddress("GenMuPhi", &GenMuPhi, &b_GenMuPhi);
   fChain->SetBranchAddress("GenElecNumber", &GenElecNumber, &b_GenElecNumber);
   fChain->SetBranchAddress("GenElecPromt", &GenElecPromt, &b_GenElecPromt);
   fChain->SetBranchAddress("GenElecTauDecay", &GenElecTauDecay, &b_GenElecTauDecay);
   fChain->SetBranchAddress("GenElecPt", &GenElecPt, &b_GenElecPt);
   fChain->SetBranchAddress("GenElecEta", &GenElecEta, &b_GenElecEta);
   fChain->SetBranchAddress("GenElecPhi", &GenElecPhi, &b_GenElecPhi);
*/
}

Bool_t RA2LostLeptonAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef RA2LostLeptonAnalyzer_cxx

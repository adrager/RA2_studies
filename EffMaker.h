//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 13 16:08:56 2013 by ROOT version 5.32/00
// from TTree RA2LostLeptonPreSelection/RA2LostLeptonPreSelection
// found on file: RA2LostLeptonSelection.root
//////////////////////////////////////////////////////////

#ifndef EffMaker_h
#define EffMaker_h
#include "GlobalVars.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
TH2F* ratioCalculator (TH2F *passTH2, TH2F *failTH2);
TH1F* ratioCalculator(TH1F* passTH1, TH1F* failTH1);
class EffMaker : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   TTree* tExpectation_;
   TFile* fExpectation_;
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
   Float_t         HTJetsPt[8];   //[HTJetsNum]
   Float_t         HTJetsEta[8];   //[HTJetsNum]
   Float_t         HTJetsPhi[8];   //[HTJetsNum]
   Float_t         HTJetsE[8];   //[HTJetsNum]
   UShort_t        MHTJetsNum;
   Float_t         MHTJetsPt[8];   //[MHTJetsNum]
   Float_t         MHTJetsEta[8];   //[MHTJetsNum]
   Float_t         MHTJetsPhi[8];   //[MHTJetsNum]
   Float_t         MHTJetsE[8];   //[MHTJetsNum]
   UShort_t        patMuonsPFIDNum;
   Float_t         patMuonsPFIDPt[2];   //[patMuonsPFIDNum]
   Float_t         patMuonsPFIDEta[2];   //[patMuonsPFIDNum]
   Float_t         patMuonsPFIDPhi[2];   //[patMuonsPFIDNum]
   Float_t         patMuonsPFIDE[2];   //[patMuonsPFIDNum]
   UShort_t        patMuonsPFIDIsoNum;
   Float_t         patMuonsPFIDIsoPt[1];   //[patMuonsPFIDIsoNum]
   Float_t         patMuonsPFIDIsoEta[1];   //[patMuonsPFIDIsoNum]
   Float_t         patMuonsPFIDIsoPhi[1];   //[patMuonsPFIDIsoNum]
   Float_t         patMuonsPFIDIsoE[1];   //[patMuonsPFIDIsoNum]
   UShort_t        ra2ElectronsIDNum;
   Float_t         ra2ElectronsIDPt[2];   //[patElectronsIDNum]
   Float_t         ra2ElectronsIDEta[2];   //[patElectronsIDNum]
   Float_t         ra2ElectronsIDPhi[2];   //[patElectronsIDNum]
   Float_t         ra2ElectronsIDE[2];   //[patElectronsIDNum]
   UShort_t        patElectronsIDIsoNum;
   Float_t         patElectronsIDIsoPt[2];   //[patElectronsIDIsoNum]
   Float_t         patElectronsIDIsoEta[2];   //[patElectronsIDIsoNum]
   Float_t         patElectronsIDIsoPhi[2];   //[patElectronsIDIsoNum]
   Float_t         patElectronsIDIsoE[2];   //[patElectronsIDIsoNum]
   UShort_t        MC;
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

   // additiona varaibles
UShort_t muIso_, muReco_, muAcc_, muMTW_;
UShort_t elecIso_, elecReco_, elecAcc_;
UShort_t total_, elecTotal_, muTotal_, totalMTW_, totalDiLep_;
Float_t muIsoTotal_, muRecoTotal_, muAccTotal_, muMTWTotal_;
Float_t elecIsoTotal_, elecRecoTotal_, elecAccTotal_;
Float_t mtw_;
Float_t totalExpectation_, muIsoExp_, muRecoExp_, muAccExp_, elecIsoExp_, elecRecoExp_, elecAccExp_;
UShort_t MuGenNum_;
Float_t MuGenPt_[20];
Float_t MuGenEta_[20];
Float_t MuGenPhi_[20];
UShort_t MuRecoNum_, MuIsoNum_;
Float_t MuRecoPt_[20];
Float_t MuRecoEta_[20];
Float_t MuRecoPhi_[20];
UShort_t ElecGenNum_;
Float_t ElecGenPt_[20];
Float_t ElecGenEta_[20];
Float_t ElecGenPhi_[20];
UShort_t ElecRecoNum_, ElecIsoNum_;
Float_t ElecRecoPt_[20];
Float_t ElecRecoEta_[20];
Float_t ElecRecoPhi_[20];
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
   TBranch        *b_MC;   //!
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

   EffMaker(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~EffMaker() { }
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

   ClassDef(EffMaker,0);
TFile* fEffOut;
TH2F *MuonIso0Fail, *MuonIsoLowFail, *MuonIso1Fail, *MuonIso2Fail, *MuonAccFail, *MuonReco0Fail, *MuonRecoLowFail, *MuonReco1Fail, *MuonReco2Fail;
TH2F *ElecIso0Fail, *ElecIsoLowFail, *ElecIso1Fail, *ElecIso2Fail, *ElecAccFail, *ElecReco0Fail, *ElecRecoLowFail, *ElecReco1Fail, *ElecReco2Fail;
TH1F *MTWNJetFail;
TH2F *MTWMHTNJetFail;
int events, number;


};

#endif

#ifdef EffMaker_cxx
void EffMaker::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   GenMuPromt = 0;
   GenMuTauDecay = 0;
   GenMuPt = 0;
   GenMuEta = 0;
   GenMuPhi = 0;
   GenElecPromt = 0;
   GenElecTauDecay = 0;
   GenElecPt = 0;
   GenElecEta = 0;
   GenElecPhi = 0;
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
   fChain->SetBranchAddress("MC", &MC, &b_MC);
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
}

Bool_t EffMaker::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef EffMaker_cxx

#include <vector>
#include <iostream>
#include <strstream>
#include <iomanip>
#include <map>


void data_card ()
{
	//gROOT->SetBatch(true);

// Define search bins and variables to use

	cout.setf(ios::fixed);
	cout<<setprecision(2);

// scale factor for MC to data!!! 3.789 for 19.78 fb
//double scale= 3.789;
	double scale=1;
//change here between true and false to run closure or prediction on data
	bool data=false;
	bool debug =false;
	if(data)
	{
		scale=1;
		cout<<"Running On Data for prediction and datacard!"<<endl;
	}
	else
	{
		cout<<"Running On MC for closure tests!"<<endl;
		scale=3.789;
	}
	// set here the NUMBER OF BINS IMPORTANT!!
	static const int BINS =48;

	std::map<int,double*> binmap;
	cout<<"Selected amount of bins"<<BINS<<endl;
	// bin definition {LowNjet,HighNejt,LowHT,HighHT,LowMHT,HighMHT}
	double bin0 [6] = {3,100,500,10000,200,10000};


	double bin1 [6] = {3,5,500,800,200,300};
	binmap[1]=bin1;
	double bin2 [6] = {3,5,500,800,300,450};
	binmap[2]=bin2;
	double bin3 [6] = {3,5,500,800,450,600};
	binmap[3]=bin3;
	double bin4 [6] = {3,5,500,800,600,10000};
	binmap[4]=bin4;

	double bin5 [6] = {3,5,800,1000,200,300};
	binmap[5]=bin5;

	double bin6 [6] = {3,5,800,1000,300,450};
	binmap[6]=bin6;

	double bin7 [6] = {3,5,800,1000,450,600};
	binmap[7]=bin7;
	double bin8 [6] = {3,5,800,1000,600,10000};
	binmap[8]=bin8;

	double bin9 [6] = {3,5,1000,1250,200,300};
	binmap[9]=bin9;
	double bin10 [6] = {3,5,1000,1250,300,450};
	binmap[10]=bin10;
	double bin11 [6] = {3,5,1000,1250,450,600};
	binmap[11]=bin11;
	double bin12 [6] = {3,5,1000,1250,600,10000};
	binmap[12]=bin12;

	double bin13 [6] = {3,5,1250,1500,200,300};
	binmap[13]=bin13;
	double bin14 [6] = {3,5,1250,1500,300,450};
	binmap[14]=bin14;
	double bin15 [6] = {3,5,1250,1500,450,10000};
	binmap[15]=bin15;

	double bin16 [6] = {3,5,1500,10000,200,300};
	binmap[16]=bin16;
	double bin17 [6] = {3,5,1500,10000,300,10000};
	binmap[17]=bin17;



	double bin18 [6] = {6,7,500,800,200,300};
	binmap[18]=bin18;
	double bin19 [6] = {6,7,500,800,300,450};
	binmap[19]=bin19;
	double bin20 [6] = {6,7,500,800,450,10000};
	binmap[20]=bin20;
 
	double bin21 [6] = {6,7,800,1000,200,300};
	binmap[21]=bin21;
	double bin22 [6] = {6,7,800,1000,300,450};
	binmap[22]=bin22;
	double bin23 [6] = {6,7,800,1000,450,10000};
	binmap[23]=bin23;

	double bin24 [6] = {6,7,1000,1250,200,300};
	binmap[24]=bin24;
	double bin25 [6] = {6,7,1000,1250,300,450};
	binmap[25]=bin25;
	double bin26 [6] = {6,7,1000,1250,450,10000};
	binmap[26]=bin26;

	double bin27 [6] = {6,7,1250,1500,200,300};
	binmap[27]=bin27;
	double bin28 [6] = {6,7,1250,1500,300,450};
	binmap[28]=bin28;
	double bin29 [6] = {6,7,1250,1500,450,10000};
	binmap[29]=bin29;

	double bin30 [6] = {6,7,1500,10000,200,300};
	binmap[30]=bin30;
	double bin31 [6] = {6,7,1500,10000,300,10000};
	binmap[31]=bin31;



	double bin32 [6] = {8,10000,500,800,200,10000};
	binmap[32]=bin32;
 
	double bin33 [6] = {8,10000,800,1000,200,10000};
	binmap[33]=bin33;

	double bin34 [6] = {8,10000,1000,1250,200,10000};
	binmap[34]=bin34;

	double bin35 [6] = {8,10000,1250,1500,200,10000};
	binmap[35]=bin35;

	double bin36 [6] = {8,10000,1500,10000,200,10000};
	binmap[36]=bin36;

	// new baseline with MHT > 100
	double bin37 [6] = {3,5,800,1000,100,200};
	binmap[37]=bin37;
	
	double bin38 [6] = {3,5,1000,1200,100,200};
	binmap[38]=bin38;
	
	double bin39 [6] = {3,5,1200,1500,100,200};
	binmap[39]=bin39;
	
	double bin40 [6] = {3,5,1500,10000,100,200};
	binmap[40]=bin40;
	
	double bin41 [6] = {6,7,800,1000,100,200};
	binmap[41]=bin41;
	
	double bin42 [6] = {6,7,1000,1200,100,200};
	binmap[42]=bin42;
	
	double bin43 [6] = {6,7,1200,1500,100,200};
	binmap[43]=bin43;
	
	double bin44 [6] = {6,7,1500,10000,100,200};
	binmap[44]=bin44;
	
	double bin45 [6] = {8,1000,800,1000,100,200};
	binmap[45]=bin45;
	
	double bin46 [6] = {8,1000,1000,1200,100,200};
	binmap[46]=bin46;
	
	double bin47 [6] = {8,1000,1200,1500,100,200};
	binmap[47]=bin47;
	
	double bin48 [6] = {8,1000,1500,10000,100,200};
	binmap[48]=bin48;


	for(int i=1;i<BINS+1;i++)
	{
		cout<<"Bin["<<i<<"] Njet["<<binmap[i][0]<<","<<binmap[i][1]<<"],HT["<<binmap[i][2]<<","<<binmap[i][3]<<"],MHT["<<binmap[i][4]<<","<<binmap[i][5]<<"]"<<endl;
	}
	
	// MC closure
	// prediction for each bin and baselines
	// baseline
	Float_t oldBaselinetotalWeightMTWDiLep=0;
	Float_t oldBaselinetotalWeightMTWDiLepStat=0;
	Float_t newBaselinetotalWeightMTWDiLep=0;
	Float_t newBaselinetotalWeightMTWDiLepStat=0;
	Float_t extremBaselinetotalWeightMTWDiLep=0;
	Float_t extremBaselinetotalWeightMTWDiLepStat=0;
	// seperate for each contribution
	Float_t muIsoWeigthOldBaseline=0;
	Float_t muIsoWeigthOldBaselineStat=0;
	Float_t muRecoWeigthOldBaseline=0;
	Float_t muRecoWeigthOldBaselineStat=0;
	Float_t muAccWeigthOldBaseline=0;
	Float_t muAccWeigthOldBaselineStat=0;
	Float_t elecIsoWeigthOldBaseline=0;
	Float_t elecIsoWeigthOldBaselineStat=0;
	Float_t elecRecoWeigthOldBaseline=0;
	Float_t elecRecoWeigthOldBaselineStat=0;
	Float_t elecAccWeigthOldBaseline=0;
	Float_t elecAccWeigthOldBaselineStat=0;
	// search bins variables
	vector<double> mctotalWeightMTWDiLep(BINS,0);
	vector<double> mctotalWeightMTWDiLepStat(BINS,0);
	// separately for each contribution
	vector<double> mcMuIsototalWeightMTWDiLep(BINS,0);
	vector<double> mcMuIsototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcMuRecototalWeightMTWDiLep(BINS,0);
	vector<double> mcMuRecototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcMuAcctotalWeightMTWDiLep(BINS,0);
	vector<double> mcMuAcctotalWeightMTWDiLepStat(BINS,0);
	
	vector<double> mcElecIsototalWeightMTWDiLep(BINS,0);
	vector<double> mcElecIsototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcElecRecototalWeightMTWDiLep(BINS,0);
	vector<double> mcElecRecototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcElecAcctotalWeightMTWDiLep(BINS,0);
	vector<double> mcElecAcctotalWeightMTWDiLepStat(BINS,0);
	
	// mc prediciton
	if(true)
	{
		TChain* mcPre = new TChain("mcPrediction");
		mcPre->Add("/afs/desy.de/user/a/adraeger/lostlepton2macros/results/LostLepton.root");
		Float_t HT =0;
		mcPre->SetBranchAddress("HT",&HT);
		Float_t MHT =0;
		mcPre->SetBranchAddress("MHT",&MHT);
		UShort_t NJets =0;
		mcPre->SetBranchAddress("NJets",&NJets);
		UShort_t NVtx =0;
		mcPre->SetBranchAddress("NVtx",&NVtx);
		Float_t MTW=0;
		mcPre->SetBranchAddress("MTW",&MTW);
		Float_t Weight=0;
		mcPre->SetBranchAddress("Weight",&Weight);
	
		Float_t totalWeightMTWDiLep=0;
		mcPre->SetBranchAddress("totalWeightMTWDiLep",&totalWeightMTWDiLep);
		Float_t muIsoWeight=0;
		mcPre->SetBranchAddress("muIsoWeight",&muIsoWeight);
		Float_t muRecoWeight=0;
		mcPre->SetBranchAddress("muRecoWeight",&muRecoWeight);
		Float_t muAccWeight=0;
		mcPre->SetBranchAddress("muAccWeight",&muAccWeight);
		Float_t elecIsoWeight=0;
		mcPre->SetBranchAddress("elecIsoWeight",&elecIsoWeight);
		Float_t elecRecoWeight=0;
		mcPre->SetBranchAddress("elecRecoWeight",&elecRecoWeight);
		Float_t elecAccWeight=0;
		mcPre->SetBranchAddress("elecAccWeight",&elecAccWeight);
	// beginn prediction loop
		for(int i=0; i< mcPre->GetEntries(); i++)
		{
			mcPre->GetEntry(i);
		// baselines
			if( HT > 500 && MHT >200 && NJets> 2.5 && MTW <100)
			{
				oldBaselinetotalWeightMTWDiLep+= totalWeightMTWDiLep;
				oldBaselinetotalWeightMTWDiLepStat+= totalWeightMTWDiLep * totalWeightMTWDiLep;
				muIsoWeigthOldBaseline+= muIsoWeight;
				muIsoWeigthOldBaselineStat+= muIsoWeight * muIsoWeight;
				muRecoWeigthOldBaseline+= muRecoWeight;
				muRecoWeigthOldBaselineStat+= muRecoWeight * muRecoWeight;
				muAccWeigthOldBaseline+= muAccWeight;
				muAccWeigthOldBaselineStat+= muAccWeight * muAccWeight;
				elecIsoWeigthOldBaseline+= elecIsoWeight;
				elecIsoWeigthOldBaselineStat+= elecIsoWeight * elecIsoWeight;
				elecRecoWeigthOldBaseline+= elecRecoWeight;
				elecRecoWeigthOldBaselineStat+= elecRecoWeight * elecRecoWeight;
				elecAccWeigthOldBaseline+= elecAccWeight;
				elecAccWeigthOldBaselineStat+= elecAccWeight * elecAccWeight;
			}
			if( HT >500 && MHT >100 && NJets > 1.1 && MTW <100)
			{
				newBaselinetotalWeightMTWDiLep+= totalWeightMTWDiLep;
				newBaselinetotalWeightMTWDiLepStat+= totalWeightMTWDiLep * totalWeightMTWDiLep;
			}
			if( HT > 500 && MHT >0 && NJets> 1.1 && MTW <100)
			{
				extremBaselinetotalWeightMTWDiLep+= totalWeightMTWDiLep;
				extremBaselinetotalWeightMTWDiLepStat+= totalWeightMTWDiLep * totalWeightMTWDiLep;
			}
		// search bins
			for(int ii=1; ii< BINS+1;ii++)
			{
				if (NJets<binmap[ii][0]-0.5 || NJets >binmap[ii][1]+0.3 || HT<binmap[ii][2] || HT>binmap[ii][3] || MHT <binmap[ii][4] || MHT > binmap[ii][5] || MTW > 100) continue;
				mctotalWeightMTWDiLep[ii-1]+= totalWeightMTWDiLep;
				mctotalWeightMTWDiLepStat[ii-1]+= totalWeightMTWDiLep * totalWeightMTWDiLep;				
			}
			for(int ii=1; ii< BINS+1;ii++)
			{
				if (NJets<binmap[ii][0]-0.5 || NJets >binmap[ii][1]+0.3 || HT<binmap[ii][2] || HT>binmap[ii][3] || MHT <binmap[ii][4] || MHT > binmap[ii][5]) continue;
				mcMuIsototalWeightMTWDiLep[ii-1] += muIsoWeight;
				mcMuIsototalWeightMTWDiLepStat[ii-1] += muIsoWeight * muIsoWeight;
				mcMuRecototalWeightMTWDiLep[ii-1] += muRecoWeight;
				mcMuRecototalWeightMTWDiLepStat[ii-1] += muRecoWeight * muRecoWeight;
				mcMuAcctotalWeightMTWDiLep[ii-1] += muAccWeight;
				mcMuAcctotalWeightMTWDiLepStat[ii-1] += muAccWeight * muAccWeight;
				mcElecIsototalWeightMTWDiLep[ii-1] += elecIsoWeight;
				mcElecIsototalWeightMTWDiLepStat[ii-1] += elecIsoWeight * elecIsoWeight;
				mcElecRecototalWeightMTWDiLep[ii-1] += elecRecoWeight;
				mcElecRecototalWeightMTWDiLepStat[ii-1] += elecRecoWeight * elecRecoWeight;
				mcElecAcctotalWeightMTWDiLep[ii-1] += elecAccWeight;
				mcElecAcctotalWeightMTWDiLepStat[ii-1] += elecAccWeight * elecAccWeight;
				
			}

		}
	}
// data prediction
	// MC closure
	// prediction for each bin and baselines
	// baseline
	Float_t dataoldBaselinetotalWeightMTWDiLep=0;
	Float_t dataoldBaselinetotalWeightMTWDiLepStat=0;
	Float_t datanewBaselinetotalWeightMTWDiLep=0;
	Float_t datanewBaselinetotalWeightMTWDiLepStat=0;
	Float_t dataextremBaselinetotalWeightMTWDiLep=0;
	Float_t dataextremBaselinetotalWeightMTWDiLepStat=0;
	// seperate for each contribution
	Float_t datamuIsoWeigthOldBaseline=0;
	Float_t datamuIsoWeigthOldBaselineStat=0;
	Float_t datamuRecoWeigthOldBaseline=0;
	Float_t datamuRecoWeigthOldBaselineStat=0;
	Float_t datamuAccWeigthOldBaseline=0;
	Float_t datamuAccWeigthOldBaselineStat=0;
	Float_t dataelecIsoWeigthOldBaseline=0;
	Float_t dataelecIsoWeigthOldBaselineStat=0;
	Float_t dataelecRecoWeigthOldBaseline=0;
	Float_t dataelecRecoWeigthOldBaselineStat=0;
	Float_t dataelecAccWeigthOldBaseline=0;
	Float_t dataelecAccWeigthOldBaselineStat=0;
	// search bins variables
	vector<double> datatotalWeightMTWDiLep(BINS,0);
	vector<double> datatotalWeightMTWDiLepStat(BINS,0);
	// uncertainties
	vector<double> datatotalWeightMTWDiLepMTWUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepMTWDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepDiLepUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepDiLepDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepDiBosonDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepNonCloUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepNonCloDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepMuAccUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepMuAccDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepElecAccUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepElecAccDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepMuIsoUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepMuIsoDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepElecIsoUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepElecIsoDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepMuRecoUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepMuRecoDown(BINS,0);
	vector<double> datatotalWeightMTWDiLepElecRecoUp(BINS,0);
	vector<double> datatotalWeightMTWDiLepElecRecoDown(BINS,0);
	// separately for each contribution
	vector<double> dataMuIsototalWeightMTWDiLep(BINS,0);
	vector<double> dataMuIsototalWeightMTWDiLepStat(BINS,0);
	vector<double> dataMuRecototalWeightMTWDiLep(BINS,0);
	vector<double> dataMuRecototalWeightMTWDiLepStat(BINS,0);
	vector<double> dataMuAcctotalWeightMTWDiLep(BINS,0);
	vector<double> dataMuAcctotalWeightMTWDiLepStat(BINS,0);
	
	vector<double> dataElecIsototalWeightMTWDiLep(BINS,0);
	vector<double> dataElecIsototalWeightMTWDiLepStat(BINS,0);
	vector<double> dataElecRecototalWeightMTWDiLep(BINS,0);
	vector<double> dataElecRecototalWeightMTWDiLepStat(BINS,0);
	vector<double> dataElecAcctotalWeightMTWDiLep(BINS,0);
	vector<double> dataElecAcctotalWeightMTWDiLepStat(BINS,0);
	
	// data prediciton
	if(true)
	{
		TChain* dataPre = new TChain("dataPrediction");
		dataPre->Add("/afs/desy.de/user/a/adraeger/lostlepton2macros/results/LostLepton.root");
		Float_t HT =0;
		dataPre->SetBranchAddress("HT",&HT);
		Float_t MHT =0;
		dataPre->SetBranchAddress("MHT",&MHT);
		UShort_t NJets =0;
		dataPre->SetBranchAddress("NJets",&NJets);
		UShort_t NVtx =0;
		dataPre->SetBranchAddress("NVtx",&NVtx);
		Float_t MTW=0;
		dataPre->SetBranchAddress("MTW",&MTW);
		Float_t Weight=0;
		dataPre->SetBranchAddress("Weight",&Weight);
		Float_t totalWeightMTWDiLep=0;
		dataPre->SetBranchAddress("totalWeightMTWDiLep",&totalWeightMTWDiLep);	
		// uncertainties
		Float_t totalWeightMTWDiLepUp=0;
		dataPre->SetBranchAddress("totalWeightMTWDiLepUp",&totalWeightMTWDiLepUp);
		Float_t totalWeightMTWDiLepDown=0;
		dataPre->SetBranchAddress("totalWeightMTWDiLepDown",&totalWeightMTWDiLepDown);
		Float_t totalWeightMTWUp=0;
		dataPre->SetBranchAddress("totalWeightMTWUp",&totalWeightMTWUp);
		Float_t totalWeightMTWDown=0;
		dataPre->SetBranchAddress("totalWeightMTWDown",&totalWeightMTWDown);	
		Float_t muAccUp=0;
		dataPre->SetBranchAddress("muAccUp",&muAccUp);
		Float_t muAccDown=0;
		dataPre->SetBranchAddress("muAccDown",&muAccDown);
		Float_t elecAccUp=0;
		dataPre->SetBranchAddress("elecAccUp",&elecAccUp);
		Float_t elecAccDown=0;
		dataPre->SetBranchAddress("elecAccDown",&elecAccDown);
		Float_t totalWeightMTWDiLepDiBosonDown=0;
		dataPre->SetBranchAddress("totalWeightMTWDiLepDiBosonDown",&totalWeightMTWDiLepDiBosonDown);
		Float_t totalWeightMTWDiLepDiNonCloUp=0;
		dataPre->SetBranchAddress("totalWeightMTWDiLepDiNonCloUp",&totalWeightMTWDiLepDiNonCloUp);
		Float_t totalWeightMTWDiLepDiNonCloDown=0;
		dataPre->SetBranchAddress("totalWeightMTWDiLepDiNonCloDown",&totalWeightMTWDiLepDiNonCloDown);
		Float_t muonIsoTAPUp=0;
		dataPre->SetBranchAddress("muonIsoTAPUp",&muonIsoTAPUp);
		Float_t muonIsoTAPDown=0;
		dataPre->SetBranchAddress("muonIsoTAPDown",&muonIsoTAPDown);
		Float_t muonRecoTAPUp=0;
		dataPre->SetBranchAddress("muonRecoTAPUp",&muonRecoTAPUp);
		Float_t muonRecoTAPDown=0;
		dataPre->SetBranchAddress("muonRecoTAPDown",&muonRecoTAPDown);
		Float_t elecIsoTAPUp=0;
		dataPre->SetBranchAddress("elecIsoTAPUp",&elecIsoTAPUp);
		Float_t elecIsoTAPDown=0;
		dataPre->SetBranchAddress("elecIsoTAPDown",&elecIsoTAPDown);
		Float_t elecRecoTAPUp=0;
		dataPre->SetBranchAddress("elecRecoTAPUp",&elecRecoTAPUp);
		Float_t elecRecoTAPDown=0;
		dataPre->SetBranchAddress("elecRecoTAPDown",&elecRecoTAPDown);
		

		Float_t muIsoWeight=0;
		dataPre->SetBranchAddress("muIsoWeight",&muIsoWeight);
		Float_t muRecoWeight=0;
		dataPre->SetBranchAddress("muRecoWeight",&muRecoWeight);
		Float_t muAccWeight=0;
		dataPre->SetBranchAddress("muAccWeight",&muAccWeight);
		Float_t elecIsoWeight=0;
		dataPre->SetBranchAddress("elecIsoWeight",&elecIsoWeight);
		Float_t elecRecoWeight=0;
		dataPre->SetBranchAddress("elecRecoWeight",&elecRecoWeight);
		Float_t elecAccWeight=0;
		dataPre->SetBranchAddress("elecAccWeight",&elecAccWeight);
	// beginn prediction loop
		for(int i=0; i< dataPre->GetEntries(); i++)
		{
			dataPre->GetEntry(i);
		// baselines
			if( HT > 500 && MHT >200 && NJets> 2.5 && MTW <100)
			{
				dataoldBaselinetotalWeightMTWDiLep+= totalWeightMTWDiLep;
				dataoldBaselinetotalWeightMTWDiLepStat+= totalWeightMTWDiLep * totalWeightMTWDiLep;
				datamuIsoWeigthOldBaseline+= muIsoWeight;
				datamuIsoWeigthOldBaselineStat+= muIsoWeight * muIsoWeight;
				datamuRecoWeigthOldBaseline+= muRecoWeight;
				datamuRecoWeigthOldBaselineStat+= muRecoWeight * muRecoWeight;
				datamuAccWeigthOldBaseline+= muAccWeight;
				datamuAccWeigthOldBaselineStat+= muAccWeight * muAccWeight;
				dataelecIsoWeigthOldBaseline+= elecIsoWeight;
				dataelecIsoWeigthOldBaselineStat+= elecIsoWeight * elecIsoWeight;
				dataelecRecoWeigthOldBaseline+= elecRecoWeight;
				dataelecRecoWeigthOldBaselineStat+= elecRecoWeight * elecRecoWeight;
				dataelecAccWeigthOldBaseline+= elecAccWeight;
				dataelecAccWeigthOldBaselineStat+= elecAccWeight * elecAccWeight;
			}
			if( HT >500 && MHT >100 && NJets > 1.1 && MTW <100)
			{
				datanewBaselinetotalWeightMTWDiLep+= totalWeightMTWDiLep;
				datanewBaselinetotalWeightMTWDiLepStat+= totalWeightMTWDiLep * totalWeightMTWDiLep;
			}
			if( HT > 500 && MHT >0 && NJets> 1.1 && MTW <100)
			{
				dataextremBaselinetotalWeightMTWDiLep+= totalWeightMTWDiLep;
				dataextremBaselinetotalWeightMTWDiLepStat+= totalWeightMTWDiLep * totalWeightMTWDiLep;
			}
		// search bins
			for(int ii=1; ii< BINS+1;ii++)
			{
				if (NJets<binmap[ii][0]-0.5 || NJets >binmap[ii][1]+0.3 || HT<binmap[ii][2] || HT>binmap[ii][3] || MHT <binmap[ii][4] || MHT > binmap[ii][5] || MTW > 100) continue;
				datatotalWeightMTWDiLep[ii-1]+= totalWeightMTWDiLep;
				datatotalWeightMTWDiLepStat[ii-1]+= totalWeightMTWDiLep * totalWeightMTWDiLep;
				datatotalWeightMTWDiLepMTWUp[ii-1]+=totalWeightMTWUp;
				datatotalWeightMTWDiLepMTWDown[ii-1]+=totalWeightMTWDown;
				datatotalWeightMTWDiLepDiLepUp[ii-1]+=totalWeightMTWDiLepUp;
				datatotalWeightMTWDiLepDiLepDown[ii-1]+=totalWeightMTWDiLepDown;
				datatotalWeightMTWDiLepDiBosonDown[ii-1]+=totalWeightMTWDiLepDiBosonDown;
				datatotalWeightMTWDiLepNonCloUp[ii-1]+=totalWeightMTWDiLepDiNonCloUp;
				datatotalWeightMTWDiLepNonCloDown[ii-1]+=totalWeightMTWDiLepDiNonCloDown;
				datatotalWeightMTWDiLepMuAccUp[ii-1]+=muAccUp;
				datatotalWeightMTWDiLepMuAccDown[ii-1]+=muAccDown;
				datatotalWeightMTWDiLepElecAccUp[ii-1]+=elecAccUp;
				datatotalWeightMTWDiLepElecAccDown[ii-1]+=elecAccDown;
				datatotalWeightMTWDiLepMuIsoUp[ii-1]+=muonIsoTAPUp;
				datatotalWeightMTWDiLepMuIsoDown[ii-1]+=muonIsoTAPDown;
				datatotalWeightMTWDiLepElecIsoUp[ii-1]+=elecIsoTAPUp;
				datatotalWeightMTWDiLepElecIsoDown[ii-1]+=elecIsoTAPDown;
				datatotalWeightMTWDiLepMuRecoUp[ii-1]+=muonRecoTAPUp;
				datatotalWeightMTWDiLepMuRecoDown[ii-1]+=muonRecoTAPDown;
				datatotalWeightMTWDiLepElecRecoUp[ii-1]+=elecRecoTAPUp;
				datatotalWeightMTWDiLepElecRecoDown[ii-1]+=elecRecoTAPDown;
			}
			for(int ii=1; ii< BINS+1;ii++)
			{
				if (NJets<binmap[ii][0]-0.5 || NJets >binmap[ii][1]+0.3 || HT<binmap[ii][2] || HT>binmap[ii][3] || MHT <binmap[ii][4] || MHT > binmap[ii][5]) continue;
				dataMuIsototalWeightMTWDiLep[ii-1] += muIsoWeight;
				dataMuIsototalWeightMTWDiLepStat[ii-1] += muIsoWeight * muIsoWeight;
				dataMuRecototalWeightMTWDiLep[ii-1] += muRecoWeight;
				dataMuRecototalWeightMTWDiLepStat[ii-1] += muRecoWeight * muRecoWeight;
				dataMuAcctotalWeightMTWDiLep[ii-1] += muAccWeight;
				dataMuAcctotalWeightMTWDiLepStat[ii-1] += muAccWeight * muAccWeight;
				dataElecIsototalWeightMTWDiLep[ii-1] += elecIsoWeight;
				dataElecIsototalWeightMTWDiLepStat[ii-1] += elecIsoWeight * elecIsoWeight;
				dataElecRecototalWeightMTWDiLep[ii-1] += elecRecoWeight;
				dataElecRecototalWeightMTWDiLepStat[ii-1] += elecRecoWeight * elecRecoWeight;
				dataElecAcctotalWeightMTWDiLep[ii-1] += elecAccWeight;
				dataElecAcctotalWeightMTWDiLepStat[ii-1] += elecAccWeight * elecAccWeight;
				
			}

		}
	}
	// mc expectation
	Float_t oldBaselineExtotalWeightMTWDiLep=0;
	Float_t oldBaselineExtotalWeightMTWDiLepStat=0;
	Float_t newBaselineExtotalWeightMTWDiLep=0;
	Float_t newBaselineExtotalWeightMTWDiLepStat=0;
	Float_t extremBaselineExtotalWeightMTWDiLep=0;
	Float_t extremBaselineExtotalWeightMTWDiLepStat=0;
	// for each contribution iso reco etc
	Float_t muIsoWeigthExOldBaseline=0;
	Float_t muIsoWeigthExOldBaselineStat=0;
	Float_t muRecoWeigthExOldBaseline=0;
	Float_t muRecoWeigthExOldBaselineStat=0;
	Float_t muAccWeigthExOldBaseline=0;
	Float_t muAccWeigthExOldBaselineStat=0;
	Float_t elecIsoWeigthExOldBaseline=0;
	Float_t elecIsoWeigthExOldBaselineStat=0;
	Float_t elecRecoWeigthExOldBaseline=0;
	Float_t elecRecoWeigthExOldBaselineStat=0;
	Float_t elecAccWeigthExOldBaseline=0;
	Float_t elecAccWeigthExOldBaselineStat=0;
	// search bins
	vector<double> mcExtotalWeightMTWDiLep(BINS,0);
	vector<double> mcExtotalWeightMTWDiLepStat(BINS,0);
	// separately for each contribution
	vector<double> mcExMuIsototalWeightMTWDiLep(BINS,0);
	vector<double> mcExMuIsototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcExMuRecototalWeightMTWDiLep(BINS,0);
	vector<double> mcExMuRecototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcExMuAcctotalWeightMTWDiLep(BINS,0);
	vector<double> mcExMuAcctotalWeightMTWDiLepStat(BINS,0);
	
	vector<double> mcExElecIsototalWeightMTWDiLep(BINS,0);
	vector<double> mcExElecIsototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcExElecRecototalWeightMTWDiLep(BINS,0);
	vector<double> mcExElecRecototalWeightMTWDiLepStat(BINS,0);
	vector<double> mcExElecAcctotalWeightMTWDiLep(BINS,0);
	vector<double> mcExElecAcctotalWeightMTWDiLepStat(BINS,0);
	if(true)
	{
		TChain* mcEx = new TChain("LostLeptonExpectation");
		mcEx->Add("/afs/desy.de/user/a/adraeger/lostlepton2macros/results/LostLepton.root");
		Float_t HT =0;
		mcEx->SetBranchAddress("HT",&HT);
		Float_t MHT =0;
		mcEx->SetBranchAddress("MHT",&MHT);
		UShort_t NJets =0;
		mcEx->SetBranchAddress("NJets",&NJets);
		UShort_t NVtx =0;
		mcEx->SetBranchAddress("NVtx",&NVtx);
		Float_t MTW=0;
		mcEx->SetBranchAddress("MTW",&MTW);
		Float_t Weight=0;
		mcEx->SetBranchAddress("Weight",&Weight);
	
		UShort_t TotalPassed=0;
		mcEx->SetBranchAddress("TotalPassed",&TotalPassed);
		// separately for each contribution
		UShort_t MuIsoPassed=0;
		mcEx->SetBranchAddress("MuIsoPassed",&MuIsoPassed);
		UShort_t MuRecoPassed=0;
		mcEx->SetBranchAddress("MuRecoPassed",&MuRecoPassed);
		UShort_t MuAccPassed=0;
		mcEx->SetBranchAddress("MuAccPassed",&MuAccPassed);
		UShort_t ElecIsoPassed=0;
		mcEx->SetBranchAddress("ElecIsoPassed",&ElecIsoPassed);
		UShort_t ElecRecoPassed=0;
		mcEx->SetBranchAddress("ElecRecoPassed",&ElecRecoPassed);
		UShort_t ElecAccPassed=0;
		mcEx->SetBranchAddress("ElecAccPassed",&ElecAccPassed);
	// beginn expectation loop
		for(int i=0; i< mcEx->GetEntries(); i++)
		{
			mcEx->GetEntry(i);
		// baselines
			if( HT > 500 && MHT >200 && NJets> 2.5 && TotalPassed==0)
			{
				oldBaselineExtotalWeightMTWDiLep+= Weight;
				oldBaselineExtotalWeightMTWDiLepStat+= Weight * Weight;
				if(MuIsoPassed==0)
				{
					muIsoWeigthExOldBaseline+= Weight;
					muIsoWeigthExOldBaselineStat+= Weight * Weight;
				}
				if(MuRecoPassed==0)
				{
					muRecoWeigthExOldBaseline+= Weight;
					muRecoWeigthExOldBaselineStat+= Weight * Weight;
				}
				if(MuAccPassed==0)
				{
					muAccWeigthExOldBaseline+= Weight;
					muAccWeigthExOldBaselineStat+= Weight * Weight;
				}
				if(ElecIsoPassed==0)
				{
					elecIsoWeigthExOldBaseline+= Weight;
					elecIsoWeigthExOldBaselineStat+= Weight * Weight;
				}
				if(ElecRecoPassed==0)
				{
					elecRecoWeigthExOldBaseline+= Weight;
					elecRecoWeigthExOldBaselineStat+= Weight * Weight;
				}
				if(ElecAccPassed==0)
				{
					elecAccWeigthExOldBaseline+= Weight;
					elecAccWeigthExOldBaselineStat+= Weight * Weight;
				}
			}
			if( HT >500 && MHT >100 && NJets > 1.1 && TotalPassed==0)
			{
				newBaselineExtotalWeightMTWDiLep+= Weight;
				newBaselineExtotalWeightMTWDiLepStat+= Weight * Weight;
			}
			if( HT > 500 && MHT >0 && NJets> 1.1 && TotalPassed==0)
			{
				extremBaselineExtotalWeightMTWDiLep+= Weight;
				extremBaselineExtotalWeightMTWDiLepStat+= Weight * Weight;
			}
		// search bins
			for(int ii=1; ii< BINS+1;ii++)
			{
				if (NJets<binmap[ii][0]-0.5 || NJets >binmap[ii][1]+0.3 || HT<binmap[ii][2] || HT>binmap[ii][3] || MHT <binmap[ii][4] || MHT > binmap[ii][5] || TotalPassed!=0) continue;
				mcExtotalWeightMTWDiLep[ii-1]+= Weight;
				mcExtotalWeightMTWDiLepStat[ii-1]+= Weight * Weight;
				if(MuIsoPassed==0)
				{
					mcExMuIsototalWeightMTWDiLep[ii-1]+= Weight;
					mcExMuIsototalWeightMTWDiLepStat[ii-1]+= Weight * Weight;
				}
				if(MuRecoPassed==0)
				{
					mcExMuRecototalWeightMTWDiLep[ii-1]+= Weight;
					mcExMuRecototalWeightMTWDiLepStat[ii-1]+= Weight * Weight;
				}
				if(MuAccPassed==0)
				{
					mcExMuAcctotalWeightMTWDiLep[ii-1]+= Weight;
					mcExMuAcctotalWeightMTWDiLepStat[ii-1]+= Weight * Weight;
				}
				if(ElecIsoPassed==0)
				{
					mcExElecIsototalWeightMTWDiLep[ii-1]+= Weight;
					mcExElecIsototalWeightMTWDiLepStat[ii-1]+= Weight * Weight;
				}
				if(ElecRecoPassed==0)
				{
					mcExElecRecototalWeightMTWDiLep[ii-1]+= Weight;
					mcExElecRecototalWeightMTWDiLepStat[ii-1]+= Weight * Weight;
				}
				if(ElecAccPassed==0)
				{
					mcExElecAcctotalWeightMTWDiLep[ii-1]+= Weight;
					mcExElecAcctotalWeightMTWDiLepStat[ii-1]+= Weight * Weight;
				}
				
			}

		}
	}

	// print results
	// mc prediciton for each baseline and search bins
	double lowNjetTemp=0;
	cout<<"MC prediction:"<<endl;
	cout<<"OldBaseline: HT > 500 && MHT > 200 && NJets> 2.5 && MTW <100, total Prediction: "<<oldBaselinetotalWeightMTWDiLep<<"+-"<<sqrt(oldBaselinetotalWeightMTWDiLepStat);
	cout<<" , Expectation:"<<oldBaselineExtotalWeightMTWDiLep<<"+-"<<sqrt(oldBaselineExtotalWeightMTWDiLepStat)<<endl;
	cout<<"NewBaseline: HT > 500 && MHT > 100 && NJets> 1.5 && MTW <100, total Prediction: "<<newBaselinetotalWeightMTWDiLep<<"+-"<<sqrt(newBaselinetotalWeightMTWDiLepStat);
	cout<<" , Expectation:"<<newBaselineExtotalWeightMTWDiLep<<"+-"<<sqrt(newBaselineExtotalWeightMTWDiLepStat)<<endl;
	cout<<"ExtremBaseline: HT > 500 && MHT >0 && NJets> 1.5 && MTW <100, total Prediction: "<<extremBaselinetotalWeightMTWDiLep<<"+-"<<sqrt(extremBaselinetotalWeightMTWDiLepStat);
	cout<<" , Expectation:"<<extremBaselineExtotalWeightMTWDiLep<<"+-"<<sqrt(extremBaselineExtotalWeightMTWDiLepStat)<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"Separately for each contribution (old baseline)"<<endl;
	cout<<"MuIso Prediction:"<< muIsoWeigthOldBaseline<<"+-"<<sqrt(muIsoWeigthOldBaselineStat)<<" expectation"<<muIsoWeigthExOldBaseline<<"+-"<<sqrt(muIsoWeigthExOldBaselineStat)<<endl;
	cout<<"MuReco Prediction:"<< muRecoWeigthOldBaseline<<"+-"<<sqrt(muRecoWeigthOldBaselineStat)<<" expectation"<<muRecoWeigthExOldBaseline<<"+-"<<sqrt(muRecoWeigthExOldBaselineStat)<<endl;
	cout<<"MuAcc Prediction:"<< muAccWeigthOldBaseline<<"+-"<<sqrt(muAccWeigthOldBaselineStat)<<" expectation"<<muAccWeigthExOldBaseline<<"+-"<<sqrt(muAccWeigthExOldBaselineStat)<<endl;
	cout<<"ElecIso Prediction:"<< elecIsoWeigthOldBaseline<<"+-"<<sqrt(elecIsoWeigthOldBaselineStat)<<" expectation"<<elecIsoWeigthExOldBaseline<<"+-"<<sqrt(elecIsoWeigthExOldBaselineStat)<<endl;
	cout<<"ElecReco Prediction:"<< elecRecoWeigthOldBaseline<<"+-"<<sqrt(elecRecoWeigthOldBaselineStat)<<" expectation"<<elecRecoWeigthExOldBaseline<<"+-"<<sqrt(elecRecoWeigthExOldBaselineStat)<<endl;
	cout<<"ElecAcc Prediction:"<< elecAccWeigthOldBaseline<<"+-"<<sqrt(elecAccWeigthOldBaselineStat)<<" expectation"<<elecAccWeigthExOldBaseline<<"+-"<<sqrt(elecAccWeigthExOldBaselineStat)<<endl;
	cout<<"Check Sum Prediction"<<muIsoWeigthExOldBaseline + muRecoWeigthExOldBaseline + muAccWeigthExOldBaseline + elecIsoWeigthExOldBaseline + elecRecoWeigthExOldBaseline + elecAccWeigthExOldBaseline<<" should similar(no MTW cut and di lep correction applied):"<<oldBaselinetotalWeightMTWDiLep<<endl;
	cout<<"Check Sum Expectation"<<muIsoWeigthExOldBaseline + muRecoWeigthExOldBaseline + muAccWeigthExOldBaseline + elecIsoWeigthExOldBaseline + elecRecoWeigthExOldBaseline + elecAccWeigthExOldBaseline<<" should be:"<<oldBaselineExtotalWeightMTWDiLep<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"MC search bin predictions:"<<endl;
	Float_t testSum=0;
	for (int i=0;i<BINS;i++)
	{
		if(lowNjetTemp < binmap[i+1][0]-0.5 || lowNjetTemp > binmap[i+1][0]+0.5)
		{
			cout<<"NJets["<<binmap[i+1][0]<<","<<binmap[i+1][1]<<"]"<<std::endl;
			lowNjetTemp=binmap[i+1][0];
			std::cout<<"\\HT (GeV)& \\MHT (GeV)& Pred. & Stat. & Expec. & Stat. & Ratio (pre/exp) & Stat. \\\\"<<std::endl;
			std::cout<<"\\hline"<<std::endl;
		}
		// ratio computing 
		double totalPrediction=mctotalWeightMTWDiLep[i]*scale;
		double totalPredictionStat=sqrt(mctotalWeightMTWDiLepStat[i])*scale;
		double totalExpectation=mcExtotalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExtotalWeightMTWDiLepStat[i])*scale;
		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );

		cout<<binmap[i+1][2]<<"\\ldots "<<binmap[i+1][3]<<"& "<<binmap[i+1][4]<<" \\ldots "<<binmap[i+1][5] <<" &";
		testSum+=mctotalWeightMTWDiLep[i];
		cout<<mctotalWeightMTWDiLep[i];

		cout<<" &"<<sqrt(mctotalWeightMTWDiLepStat[i]);
		cout<<" &"<<mcExtotalWeightMTWDiLep[i];
		cout<<" &"<<sqrt(mcExtotalWeightMTWDiLepStat[i]);
		cout<<" &              "<<ratio;
		cout<<" &              "<<ratioStat;
		cout		<<" \\\\ "<<std::endl;
	}
	cout<<"TestSum Prediction of each search bin should be equal to old baseline selection:"<<testSum<<endl;
	cout<<"OldBaseline"<<oldBaselinetotalWeightMTWDiLep<<endl;
	lowNjetTemp=0;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"Data search bin predictions:"<<endl;
	Float_t testSum=0;
	for (int i=0;i<BINS;i++)
	{
		if(lowNjetTemp < binmap[i+1][0]-0.5 || lowNjetTemp > binmap[i+1][0]+0.5)
		{
			cout<<"NJets["<<binmap[i+1][0]<<","<<binmap[i+1][1]<<"]"<<std::endl;
			lowNjetTemp=binmap[i+1][0];
			std::cout<<"\\HT (GeV)& \\MHT (GeV)& Pred. & Stat. & M_{T} & diLep & other SM & non closure & muAcc & elecAcc & muIso & muReco & elecIso & elecReco & Tot. Sys. \\\\"<<std::endl;
			std::cout<<"\\hline"<<std::endl;
		}
		// ratio computing 
		

		cout<<binmap[i+1][2]<<"\\ldots "<<binmap[i+1][3]<<"& "<<binmap[i+1][4]<<" \\ldots "<<binmap[i+1][5] <<" &";
		testSum+=datatotalWeightMTWDiLep[i];
		cout<<datatotalWeightMTWDiLep[i];

		cout<<" &"<<sqrt(datatotalWeightMTWDiLepStat[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiBosonDown[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]);
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]);
		cout<<" &$_{-"<<sqrt(
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiBosonDown[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiBosonDown[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) 
				   );
		cout<<"}^{+"<<sqrt(
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) 
				  );
				cout<<"}$";

		cout		<<" \\\\ "<<std::endl;
	}
	cout<<"TestSum Prediction of each search bin should be equal to old baseline selection:"<<testSum<<endl;
	cout<<"OldBaseline"<<dataoldBaselinetotalWeightMTWDiLep<<endl;
	lowNjetTemp=0;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"Data search bin predictions in PERCENT:"<<endl;
	Float_t testSum=0;
	for (int i=0;i<BINS;i++)
	{
		if(lowNjetTemp < binmap[i+1][0]-0.5 || lowNjetTemp > binmap[i+1][0]+0.5)
		{
			cout<<"NJets["<<binmap[i+1][0]<<","<<binmap[i+1][1]<<"]"<<std::endl;
			lowNjetTemp=binmap[i+1][0];
			std::cout<<"\\HT (GeV)& \\MHT (GeV)& Pred. & Stat. & M_{T} & diLep & other SM & non closure & muAcc & elecAcc & muIso & muReco & elecIso & elecReco & Tot. Sys. \\\\"<<std::endl;
			std::cout<<"\\hline"<<std::endl;
		}
		// ratio computing 
		

		cout<<binmap[i+1][2]<<"\\ldots "<<binmap[i+1][3]<<"& "<<binmap[i+1][4]<<" \\ldots "<<binmap[i+1][5] <<" &";
		testSum+=datatotalWeightMTWDiLep[i];
		cout<<datatotalWeightMTWDiLep[i];

		cout<<" &"<<sqrt(datatotalWeightMTWDiLepStat[i])/ datatotalWeightMTWDiLep[i] * 100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i])/datatotalWeightMTWDiLep[i] *100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiBosonDown[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &"<<std::fabs(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i])/datatotalWeightMTWDiLep[i]*100;
		cout<<" &$_{-"<<sqrt(
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiBosonDown[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiBosonDown[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) 
				   )/datatotalWeightMTWDiLep[i]*100;
			cout	<<"}^{+"<<sqrt(
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMTWUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepDiLepUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepNonCloUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecAccUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepMuRecoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecIsoUp[i]) +
				(datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) * (datatotalWeightMTWDiLep[i] - datatotalWeightMTWDiLepElecRecoUp[i]) 
					      )/datatotalWeightMTWDiLep[i]*100;
			cout	<<"} $";

		cout		<<" \\\\ "<<std::endl;
	}
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	
		
	cout<<"MC search bin separately for iso reco acc and mu:"<<endl;
	Float_t testSum=0;
	for (int i=0;i<BINS;i++)
	{
		if(lowNjetTemp < binmap[i+1][0]-0.5 || lowNjetTemp > binmap[i+1][0]+0.5) 
		{
			cout<<"NJets["<<binmap[i+1][0]<<","<<binmap[i+1][1]<<"]"<<std::endl;
			lowNjetTemp=binmap[i+1][0];
			std::cout<<"\\HT (GeV)& \\MHT (GeV)& TotalPredi & MuAcc & Elec Acc & Sum All \\\\"<<std::endl;
			std::cout<<"\\hline"<<std::endl;
		}
		cout<<binmap[i+1][2]<<"\\ldots "<<binmap[i+1][3]<<"& "<<binmap[i+1][4]<<" \\ldots "<<binmap[i+1][5] <<" &";
		cout<<mctotalWeightMTWDiLep[i]<<"& ";
	//	cout<<mcMuIsototalWeightMTWDiLep[i];
	//	cout<<"+-"<<sqrt(mcMuIsototalWeightMTWDiLepStat[i])<<"& ";
	//	cout<<mcExMuIsototalWeightMTWDiLep[i];
	//	cout<<"+-"<<sqrt(mcExMuIsototalWeightMTWDiLepStat[i])<<"& ";	
	//	cout<<mcMuRecototalWeightMTWDiLep[i];
	//	cout<<"+-"<<sqrt(mcMuRecototalWeightMTWDiLepStat[i])<<"& ";
	//	cout<<mcExMuRecototalWeightMTWDiLep[i];
	//	cout<<"+-"<<sqrt(mcExMuRecototalWeightMTWDiLepStat[i])<<"& ";
		cout<<mcMuAcctotalWeightMTWDiLep[i]/mctotalWeightMTWDiLep[i]*100<<"& ";
		cout<<mcElecAcctotalWeightMTWDiLep[i]/mctotalWeightMTWDiLep[i]*100<<"& ";
		cout<<mcMuAcctotalWeightMTWDiLep[i]+mcElecAcctotalWeightMTWDiLep[i]+mcMuIsototalWeightMTWDiLep[i]+mcMuRecototalWeightMTWDiLep[i]+mcElecIsototalWeightMTWDiLep[i]+mcElecRecototalWeightMTWDiLep[i]<<"& ";
	//	cout<<(mcMuIsototalWeightMTWDiLep[i] + mcMuRecototalWeightMTWDiLep[i] + mcExMuAcctotalWeightMTWDiLep[i]) / (mcExMuIsototalWeightMTWDiLep[i] + mcExMuRecototalWeightMTWDiLep[i] + mcExMuAcctotalWeightMTWDiLep[i]);
		cout		<<" \\\\ "<<std::endl;
	}
	lowNjetTemp=0;
	
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"MC search bin separately for iso reco acc and elec:"<<endl;
	Float_t testSum=0;
	for (int i=0;i<BINS;i++)
	{
		if(lowNjetTemp < binmap[i+1][0]-0.5 || lowNjetTemp > binmap[i+1][0]+0.5)
		{
			cout<<"NJets["<<binmap[i+1][0]<<","<<binmap[i+1][1]<<"]"<<std::endl;
			lowNjetTemp=binmap[i+1][0];
			std::cout<<"\\HT (GeV)& \\MHT (GeV)& Elec Iso Pre. & Elec Iso Ex & Elec Reco Pre. & Elec Reco Ex & Elec Acc Pre. & Elec Acc Ex & Total Elec Pre. & Total Elec Ex. \\\\"<<std::endl;
			std::cout<<"\\hline"<<std::endl;
		}
		cout<<binmap[i+1][2]<<"\\ldots "<<binmap[i+1][3]<<"& "<<binmap[i+1][4]<<" \\ldots "<<binmap[i+1][5] <<" &";
		cout<<mcElecIsototalWeightMTWDiLep[i];
		cout<<"+-"<<sqrt(mcElecIsototalWeightMTWDiLepStat[i])<<"& ";
		cout<<mcExElecIsototalWeightMTWDiLep[i];
		cout<<"+-"<<sqrt(mcExElecIsototalWeightMTWDiLepStat[i])<<"& ";	
		cout<<mcElecRecototalWeightMTWDiLep[i];
		cout<<"+-"<<sqrt(mcElecRecototalWeightMTWDiLepStat[i])<<"& ";
		cout<<mcExElecRecototalWeightMTWDiLep[i];
		cout<<"+-"<<sqrt(mcExElecRecototalWeightMTWDiLepStat[i])<<"& ";
		cout<<mcElecAcctotalWeightMTWDiLep[i];
		cout<<"+-"<<sqrt(mcElecAcctotalWeightMTWDiLepStat[i])<<"& ";
		cout<<mcExElecAcctotalWeightMTWDiLep[i];
		cout<<"+-"<<sqrt(mcExElecAcctotalWeightMTWDiLepStat[i])<<"&    ";	
		cout<<mcElecIsototalWeightMTWDiLep[i] + mcElecRecototalWeightMTWDiLep[i] + mcExElecAcctotalWeightMTWDiLep[i]<<"& ";
		cout<<mcExElecIsototalWeightMTWDiLep[i] + mcExElecRecototalWeightMTWDiLep[i] + mcExElecAcctotalWeightMTWDiLep[i]<<"& ";
		cout<<(mcElecIsototalWeightMTWDiLep[i] + mcElecRecototalWeightMTWDiLep[i] + mcExElecAcctotalWeightMTWDiLep[i]) / (mcExElecIsototalWeightMTWDiLep[i] + mcExElecRecototalWeightMTWDiLep[i] + mcExElecAcctotalWeightMTWDiLep[i]);
		cout		<<" \\\\ "<<std::endl;
	}
	lowNjetTemp=0;
	// produce closure plots for each search bin from mc

	TH1F *ClosureTH1 = new TH1F("Closure","CMS Simulation, 8 TeV, Closure all search bins",BINS+2,0,BINS+1);
	ClosureTH1->SetBinContent(BINS+2,oldBaselinetotalWeightMTWDiLep/oldBaselineExtotalWeightMTWDiLep);
	ratioStat=sqrt( ( 1/oldBaselineExtotalWeightMTWDiLep * oldBaselinetotalWeightMTWDiLepStat )* ( 1/oldBaselineExtotalWeightMTWDiLep * oldBaselinetotalWeightMTWDiLepStat ) + (oldBaselinetotalWeightMTWDiLep/(oldBaselineExtotalWeightMTWDiLep*oldBaselineExtotalWeightMTWDiLep)* oldBaselineExtotalWeightMTWDiLepStat ) * ( oldBaselinetotalWeightMTWDiLep/(oldBaselineExtotalWeightMTWDiLep*oldBaselineExtotalWeightMTWDiLep)* oldBaselineExtotalWeightMTWDiLepStat ) );
	cout<<"baselineClosureRatio="<<oldBaselineExtotalWeightMTWDiLep/oldBaselinetotalWeightMTWDiLep<<"+-"<<ratioStat<<endl;
	ClosureTH1->SetBinError(BINS+2,ratioStat);


	int countter1=1;
	int countter2=1;
	for (int i=0;i<BINS;i++)
	{
		double totalPrediction=mctotalWeightMTWDiLep[i]*scale;
//totalPrediction=ResultWeightData[i];
		double totalPredictionStat=sqrt(mctotalWeightMTWDiLepStat[i])*scale;

		double totalExpectation=mcExtotalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExtotalWeightMTWDiLepStat[i])*scale;

		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );
//cout<<"ratio"<<ratio<<"+-"<<ratioStat<<endl;
		ClosureTH1->SetBinContent(i+1,ratio);
		ClosureTH1->SetBinError(i+1,ratioStat);
	}
	TCanvas *c1= new TCanvas("c1","");
	c1->cd();
	ClosureTH1->SetTitle("CMS Simulation, 8 TeV, Closure all search bins;Bins;Pre/Exp");
	ClosureTH1->Draw();
	// create for iso reco etc separately closure plot for all search bins
	
	TH1F *ClosureMuIsoTH1 = new TH1F("Closure","CMS Simulation, 8 TeV, Closure all search bins muIso",BINS+2,0,BINS+1);
	ClosureMuIsoTH1->SetBinContent(BINS+2,muIsoWeigthOldBaseline/muIsoWeigthExOldBaseline);
	ratioStat=sqrt( ( 1/muIsoWeigthExOldBaseline * muIsoWeigthOldBaselineStat )* ( 1/muIsoWeigthExOldBaseline * muIsoWeigthOldBaselineStat ) + (muIsoWeigthOldBaseline/(muIsoWeigthExOldBaseline*muIsoWeigthExOldBaseline)* muIsoWeigthExOldBaselineStat ) * ( muIsoWeigthOldBaseline/(muIsoWeigthExOldBaseline*muIsoWeigthExOldBaseline)* muIsoWeigthExOldBaselineStat ) );
	ClosureMuIsoTH1->SetBinError(BINS+2,ratioStat);


	countter1=1;
	countter2=1;
	for (int i=0;i<BINS;i++)
	{
		double totalPrediction=mcMuIsototalWeightMTWDiLep[i]*scale;
		double totalPredictionStat=sqrt(mcMuIsototalWeightMTWDiLepStat[i])*scale;

		double totalExpectation=mcExMuIsototalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExMuIsototalWeightMTWDiLepStat[i])*scale;

		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );
		if(ratio<0.001 || ratio>1000 || ratioStat<0.000001 || ratioStat>100000)
		{
			ratio=0.001;
			ratioStat=0.001;
		}
//cout<<"ratio"<<ratio<<"+-"<<ratioStat<<endl;
		ClosureMuIsoTH1->SetBinContent(i+1,ratio);
		ClosureMuIsoTH1->SetBinError(i+1,ratioStat);
	}
	TCanvas *c2= new TCanvas("c2","");
	c2->cd();
	ClosureMuIsoTH1->SetTitle("CMS Simulation, 8 TeV, Closure all search bins muIso;Bins;Pre/Exp");
	ClosureMuIsoTH1->Draw();
	TH1F *ClosureMuRecoTH1 = new TH1F("Closure","CMS Simulation, 8 TeV, Closure all search bins muReco",BINS+2,0,BINS+1);
	ClosureMuRecoTH1->SetBinContent(BINS+2,muRecoWeigthOldBaseline/muRecoWeigthExOldBaseline);
	ratioStat=sqrt( ( 1/muRecoWeigthExOldBaseline * muRecoWeigthOldBaselineStat )* ( 1/muRecoWeigthExOldBaseline * muRecoWeigthOldBaselineStat ) + (muRecoWeigthOldBaseline/(muRecoWeigthExOldBaseline*muRecoWeigthExOldBaseline)* muRecoWeigthExOldBaselineStat ) * ( muRecoWeigthOldBaseline/(muRecoWeigthExOldBaseline*muRecoWeigthExOldBaseline)* muRecoWeigthExOldBaselineStat ) );
	ClosureMuRecoTH1->SetBinError(BINS+2,ratioStat);


	countter1=1;
	countter2=1;
	for (int i=0;i<BINS;i++)
	{
		double totalPrediction=mcMuRecototalWeightMTWDiLep[i]*scale;
		double totalPredictionStat=sqrt(mcMuRecototalWeightMTWDiLepStat[i])*scale;

		double totalExpectation=mcExMuRecototalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExMuRecototalWeightMTWDiLepStat[i])*scale;

		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );
		if(ratio<0.001 || ratio>1000 || ratioStat<0.000001 || ratioStat>100000)
		{
			ratio=0.001;
			ratioStat=0.001;
		}
			

//cout<<"ratio"<<ratio<<"+-"<<ratioStat<<endl;
		ClosureMuRecoTH1->SetBinContent(i+1,ratio);
		ClosureMuRecoTH1->SetBinError(i+1,ratioStat);
	}
	TCanvas *c3= new TCanvas("c3","");
	c3->cd();
	ClosureMuRecoTH1->SetTitle("CMS Simulation, 8 TeV, Closure all search bins muReco;Bins;Pre/Exp");
	ClosureMuRecoTH1->Draw();
	TH1F *ClosureMuAccTH1 = new TH1F("Closure","CMS Simulation, 8 TeV, Closure all search bins muAcc",BINS+2,0,BINS+1);
	ClosureMuAccTH1->SetBinContent(BINS+2,muAccWeigthOldBaseline/muAccWeigthExOldBaseline);
	ratioStat=sqrt( ( 1/muAccWeigthExOldBaseline * muAccWeigthOldBaselineStat )* ( 1/muAccWeigthExOldBaseline * muAccWeigthOldBaselineStat ) + (muAccWeigthOldBaseline/(muAccWeigthExOldBaseline*muAccWeigthExOldBaseline)* muAccWeigthExOldBaselineStat ) * ( muAccWeigthOldBaseline/(muAccWeigthExOldBaseline*muAccWeigthExOldBaseline)* muAccWeigthExOldBaselineStat ) );
	ClosureMuAccTH1->SetBinError(BINS+2,ratioStat);


	countter1=1;
	countter2=1;
	for (int i=0;i<BINS;i++)
	{
		double totalPrediction=mcMuAcctotalWeightMTWDiLep[i]*scale;
		double totalPredictionStat=sqrt(mcMuAcctotalWeightMTWDiLepStat[i])*scale;

		double totalExpectation=mcExMuAcctotalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExMuAcctotalWeightMTWDiLepStat[i])*scale;

		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );
//cout<<"ratio"<<ratio<<"+-"<<ratioStat<<endl;
		if(ratio<0.001 || ratio>1000 || ratioStat<0.000001 || ratioStat>100000)
		{
			ratio=0.001;
			ratioStat=0.001;
		}
		ClosureMuAccTH1->SetBinContent(i+1,ratio);
		ClosureMuAccTH1->SetBinError(i+1,ratioStat);
	}
	TCanvas *c4= new TCanvas("c4","");
	c4->cd();
	ClosureMuAccTH1->SetTitle("CMS Simulation, 8 TeV, Closure all search bins muAcc;Bins;Pre/Exp");
	ClosureMuAccTH1->Draw();
	// elec
	TH1F *ClosureElecIsoTH1 = new TH1F("Closure","CMS Sieleclation, 8 TeV, Closure all search bins elecIso",BINS+2,0,BINS+1);
	ClosureElecIsoTH1->SetBinContent(BINS+2,elecIsoWeigthOldBaseline/elecIsoWeigthExOldBaseline);
	ratioStat=sqrt( ( 1/elecIsoWeigthExOldBaseline * elecIsoWeigthOldBaselineStat )* ( 1/elecIsoWeigthExOldBaseline * elecIsoWeigthOldBaselineStat ) + (elecIsoWeigthOldBaseline/(elecIsoWeigthExOldBaseline*elecIsoWeigthExOldBaseline)* elecIsoWeigthExOldBaselineStat ) * ( elecIsoWeigthOldBaseline/(elecIsoWeigthExOldBaseline*elecIsoWeigthExOldBaseline)* elecIsoWeigthExOldBaselineStat ) );
	ClosureElecIsoTH1->SetBinError(BINS+2,ratioStat);


	countter1=1;
	countter2=1;
	for (int i=0;i<BINS;i++)
	{
		double totalPrediction=mcElecIsototalWeightMTWDiLep[i]*scale;
		double totalPredictionStat=sqrt(mcElecIsototalWeightMTWDiLepStat[i])*scale;

		double totalExpectation=mcExElecIsototalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExElecIsototalWeightMTWDiLepStat[i])*scale;

		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );
//cout<<"ratio"<<ratio<<"+-"<<ratioStat<<endl;
		if(ratio<0.001 || ratio>1000 || ratioStat<0.000001 || ratioStat>100000)
		{
			ratio=0.001;
			ratioStat=0.001;
		}
		ClosureElecIsoTH1->SetBinContent(i+1,ratio);
		ClosureElecIsoTH1->SetBinError(i+1,ratioStat);
	}
	TCanvas *c5= new TCanvas("c5","");
	c5->cd();
	ClosureElecIsoTH1->SetTitle("CMS Sieleclation, 8 TeV, Closure all search bins elecIso;Bins;Pre/Exp");
	ClosureElecIsoTH1->Draw();
	TH1F *ClosureElecRecoTH1 = new TH1F("Closure","CMS Sieleclation, 8 TeV, Closure all search bins elecReco",BINS+2,0,BINS+1);
	ClosureElecRecoTH1->SetBinContent(BINS+2,elecRecoWeigthOldBaseline/elecRecoWeigthExOldBaseline);
	ratioStat=sqrt( ( 1/elecRecoWeigthExOldBaseline * elecRecoWeigthOldBaselineStat )* ( 1/elecRecoWeigthExOldBaseline * elecRecoWeigthOldBaselineStat ) + (elecRecoWeigthOldBaseline/(elecRecoWeigthExOldBaseline*elecRecoWeigthExOldBaseline)* elecRecoWeigthExOldBaselineStat ) * ( elecRecoWeigthOldBaseline/(elecRecoWeigthExOldBaseline*elecRecoWeigthExOldBaseline)* elecRecoWeigthExOldBaselineStat ) );
	ClosureElecRecoTH1->SetBinError(BINS+2,ratioStat);


	countter1=1;
	countter2=1;
	for (int i=0;i<BINS;i++)
	{
		double totalPrediction=mcElecRecototalWeightMTWDiLep[i]*scale;
		double totalPredictionStat=sqrt(mcElecRecototalWeightMTWDiLepStat[i])*scale;

		double totalExpectation=mcExElecRecototalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExElecRecototalWeightMTWDiLepStat[i])*scale;

		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );
//cout<<"ratio"<<ratio<<"+-"<<ratioStat<<endl;
		if(ratio<0.001 || ratio>1000 || ratioStat<0.000001 || ratioStat>100000)
		{
			ratio=0.001;
			ratioStat=0.001;
		}
		ClosureElecRecoTH1->SetBinContent(i+1,ratio);
		ClosureElecRecoTH1->SetBinError(i+1,ratioStat);
	}
	TCanvas *c6= new TCanvas("c6","");
	c6->cd();
	ClosureElecRecoTH1->SetTitle("CMS Sieleclation, 8 TeV, Closure all search bins elecReco;Bins;Pre/Exp");
	ClosureElecRecoTH1->Draw();
	TH1F *ClosureElecAccTH1 = new TH1F("Closure","CMS Sieleclation, 8 TeV, Closure all search bins elecAcc",BINS+2,0,BINS+1);
	ClosureElecAccTH1->SetBinContent(BINS+2,elecAccWeigthOldBaseline/elecAccWeigthExOldBaseline);
	ratioStat=sqrt( ( 1/elecAccWeigthExOldBaseline * elecAccWeigthOldBaselineStat )* ( 1/elecAccWeigthExOldBaseline * elecAccWeigthOldBaselineStat ) + (elecAccWeigthOldBaseline/(elecAccWeigthExOldBaseline*elecAccWeigthExOldBaseline)* elecAccWeigthExOldBaselineStat ) * ( elecAccWeigthOldBaseline/(elecAccWeigthExOldBaseline*elecAccWeigthExOldBaseline)* elecAccWeigthExOldBaselineStat ) );
	ClosureElecAccTH1->SetBinError(BINS+2,ratioStat);


	countter1=1;
	countter2=1;
	for (int i=0;i<BINS;i++)
	{
		double totalPrediction=mcElecAcctotalWeightMTWDiLep[i]*scale;
		double totalPredictionStat=sqrt(mcElecAcctotalWeightMTWDiLepStat[i])*scale;

		double totalExpectation=mcExElecAcctotalWeightMTWDiLep[i]*scale;
		double totalExpectationStat=sqrt(mcExElecAcctotalWeightMTWDiLepStat[i])*scale;

		double ratio=totalPrediction/totalExpectation;
		double ratioStat=sqrt( ( 1/totalExpectation * totalPredictionStat )* ( 1/totalExpectation * totalPredictionStat ) + (totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) * ( totalPrediction/(totalExpectation*totalExpectation)* totalExpectationStat ) );
//cout<<"ratio"<<ratio<<"+-"<<ratioStat<<endl;
		if(ratio<0.001 || ratio>1000 || ratioStat<0.000001 || ratioStat>100000)
		{
			ratio=0.001;
			ratioStat=0.001;
		}
		ClosureElecAccTH1->SetBinContent(i+1,ratio);
		ClosureElecAccTH1->SetBinError(i+1,ratioStat);
	}
	TCanvas *c7= new TCanvas("c7","");
	c7->cd();
	ClosureElecAccTH1->SetTitle("CMS Sieleclation, 8 TeV, Closure all search bins elecAcc;Bins;Pre/Exp");
	ClosureElecAccTH1->Draw();
	cout<<"Done!"<<endl<<"Please come again"<<endl;

}


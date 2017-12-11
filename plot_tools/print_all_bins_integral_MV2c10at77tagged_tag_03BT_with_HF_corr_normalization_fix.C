#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

void print_all_bins_integral_MV2c10at77tagged_tag_03BT_with_HF_corr_normalization_fix() {

    //TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/mu4j15/Nominal.root");
    //TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/mu4j25/Nominal.root");
    //TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/mu4j35/Nominal.root");
    //TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/mu4j55/Nominal.root");
    //TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/mu6j85/Nominal.root");
    //TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/mu6j110/Nominal.root");
    //TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/mu6j150/Nominal.root");

    //TH1F *l1 = (TH1F*)f1->Get("MV2c10at77tagged/jpt20to30MV2c10at77tagged/pTrel_data_untag");    
    //TH1F *l2 = (TH1F*)f1->Get("MV2c10at77tagged/jpt30to40MV2c10at77tagged/pTrel_data_untag");  
    //TH1F *l3 = (TH1F*)f2->Get("MV2c10at77tagged/jpt40to50MV2c10at77tagged/pTrel_data_untag");  
    //TH1F *l4 = (TH1F*)f3->Get("MV2c10at77tagged/jpt50to70MV2c10at77tagged/pTrel_data_untag");  
    //TH1F *l5 = (TH1F*)f4->Get("MV2c10at77tagged/jpt70to90MV2c10at77tagged/pTrel_data_untag");  
    //TH1F *l6 = (TH1F*)f4->Get("MV2c10at77tagged/jpt90to110MV2c10at77tagged/pTrel_data_untag");  
    //TH1F *l7 = (TH1F*)f5->Get("MV2c10at77tagged/jpt110to140MV2c10at77tagged/pTrel_data_untag");  
    //TH1F *l8 = (TH1F*)f6->Get("MV2c10at77tagged/jpt140to170MV2c10at77tagged/pTrel_data_untag");  
    //TH1F *l9 = (TH1F*)f7->Get("MV2c10at77tagged/jpt170to200MV2c10at77tagged/pTrel_data_untag");  

    ////for BT studies, use a separate output for each bin
    TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt20to30_mu4j15/Nominal.root");
    TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt30to40_mu4j15/Nominal.root");
    TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt40to50_mu4j25/Nominal.root");
    TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt50to70_mu4j35/Nominal.root");
    TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt70to90_mu4j55/Nominal.root");
    TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt90to110_mu4j55/Nominal.root");
    TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt110to140_mu6j85/Nominal.root");
    TFile *f8 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt140to170_mu6j110/Nominal.root");
    TFile *f9 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_03BT_with_HF_corr_normalization_fix/jpt170to200_mu6j150/Nominal.root");

    TH1F *l1 = (TH1F*)f1->Get("MV2c10at77tagged/jpt20to30MV2c10at77tagged/pTrel_data_untag");
    TH1F *l2 = (TH1F*)f2->Get("MV2c10at77tagged/jpt30to40MV2c10at77tagged/pTrel_data_untag");
    TH1F *l3 = (TH1F*)f3->Get("MV2c10at77tagged/jpt40to50MV2c10at77tagged/pTrel_data_untag");
    TH1F *l4 = (TH1F*)f4->Get("MV2c10at77tagged/jpt50to70MV2c10at77tagged/pTrel_data_untag");
    TH1F *l5 = (TH1F*)f5->Get("MV2c10at77tagged/jpt70to90MV2c10at77tagged/pTrel_data_untag");
    TH1F *l6 = (TH1F*)f6->Get("MV2c10at77tagged/jpt90to110MV2c10at77tagged/pTrel_data_untag");
    TH1F *l7 = (TH1F*)f7->Get("MV2c10at77tagged/jpt110to140MV2c10at77tagged/pTrel_data_untag");
    TH1F *l8 = (TH1F*)f8->Get("MV2c10at77tagged/jpt140to170MV2c10at77tagged/pTrel_data_untag");
    TH1F *l9 = (TH1F*)f9->Get("MV2c10at77tagged/jpt170to200MV2c10at77tagged/pTrel_data_untag");

    float l_val_1 = l1->Integral(1,25);
    float l_val_2 = l2->Integral(1,25);
    float l_val_3 = l3->Integral(1,25);
    float l_val_4 = l4->Integral(1,25);
    float l_val_5 = l5->Integral(1,25);
    float l_val_6 = l6->Integral(1,25);
    float l_val_7 = l7->Integral(1,25);
    float l_val_8 = l8->Integral(1,25);
    float l_val_9 = l9->Integral(1,25);

    cout <<  "pTrel_data_untag" << endl;
    cout <<  l_val_1 << endl;
    cout <<  l_val_2 << endl;
    cout <<  l_val_3 << endl;
    cout <<  l_val_4 << endl;
    cout <<  l_val_5 << endl;
    cout <<  l_val_6 << endl;
    cout <<  l_val_7 << endl;
    cout <<  l_val_8 << endl;
    cout <<  l_val_9 << endl;


}



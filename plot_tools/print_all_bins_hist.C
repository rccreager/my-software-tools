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

void print_all_bins_hist_WP_TAG_DATASET() {

    //TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j15/Nominal.root");
    //TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j25/Nominal.root");
    //TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j35/Nominal.root");
    //TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j55/Nominal.root");
    //TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j85/Nominal.root");
    //TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j110/Nominal.root");
    //TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j150/Nominal.root");

    //TH1F *l1 = (TH1F*)f1->Get("WP/jpt20to30WP/HIST");    
    //TH1F *l2 = (TH1F*)f1->Get("WP/jpt30to40WP/HIST");  
    //TH1F *l3 = (TH1F*)f2->Get("WP/jpt40to50WP/HIST");  
    //TH1F *l4 = (TH1F*)f3->Get("WP/jpt50to70WP/HIST");  
    //TH1F *l5 = (TH1F*)f4->Get("WP/jpt70to90WP/HIST");  
    //TH1F *l6 = (TH1F*)f4->Get("WP/jpt90to110WP/HIST");  
    //TH1F *l7 = (TH1F*)f5->Get("WP/jpt110to140WP/HIST");  
    //TH1F *l8 = (TH1F*)f6->Get("WP/jpt140to170WP/HIST");  
    //TH1F *l9 = (TH1F*)f7->Get("WP/jpt170to200WP/HIST");  

    ////for BT studies, use a separate output for each bin
    TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt20to30_mu4j15/Nominal.root");
    TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt30to40_mu4j15/Nominal.root");
    TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt40to50_mu4j25/Nominal.root");
    TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt50to70_mu4j35/Nominal.root");
    TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt70to90_mu4j55/Nominal.root");
    TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt90to110_mu4j55/Nominal.root");
    TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt110to140_mu6j85/Nominal.root");
    TFile *f8 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt140to170_mu6j110/Nominal.root");
    TFile *f9 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt170to200_mu6j150/Nominal.root");

    TH1F *l1 = (TH1F*)f1->Get("WP/jpt20to30WP/HIST");
    TH1F *l2 = (TH1F*)f2->Get("WP/jpt30to40WP/HIST");
    TH1F *l3 = (TH1F*)f3->Get("WP/jpt40to50WP/HIST");
    TH1F *l4 = (TH1F*)f4->Get("WP/jpt50to70WP/HIST");
    TH1F *l5 = (TH1F*)f5->Get("WP/jpt70to90WP/HIST");
    TH1F *l6 = (TH1F*)f6->Get("WP/jpt90to110WP/HIST");
    TH1F *l7 = (TH1F*)f7->Get("WP/jpt110to140WP/HIST");
    TH1F *l8 = (TH1F*)f8->Get("WP/jpt140to170WP/HIST");
    TH1F *l9 = (TH1F*)f9->Get("WP/jpt170to200WP/HIST");

    int l_bin_1 = l1->FindFirstBinAbove(0.5);
    int l_bin_2 = l2->FindFirstBinAbove(0.5);
    int l_bin_3 = l3->FindFirstBinAbove(0.5);
    int l_bin_4 = l4->FindFirstBinAbove(0.5);
    int l_bin_5 = l5->FindFirstBinAbove(0.5);
    int l_bin_6 = l6->FindFirstBinAbove(0.5);
    int l_bin_7 = l7->FindFirstBinAbove(0.5);
    int l_bin_8 = l8->FindFirstBinAbove(0.5);
    int l_bin_9 = l9->FindFirstBinAbove(0.5); 

    float l_val_1 = l1->GetBinCenter(l_bin_1);
    float l_val_2 = l2->GetBinCenter(l_bin_2);
    float l_val_3 = l3->GetBinCenter(l_bin_3);
    float l_val_4 = l4->GetBinCenter(l_bin_4);
    float l_val_5 = l5->GetBinCenter(l_bin_5);
    float l_val_6 = l6->GetBinCenter(l_bin_6);
    float l_val_7 = l7->GetBinCenter(l_bin_7);
    float l_val_8 = l8->GetBinCenter(l_bin_8);
    float l_val_9 = l9->GetBinCenter(l_bin_9);

    cout <<  "HIST" << endl;
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



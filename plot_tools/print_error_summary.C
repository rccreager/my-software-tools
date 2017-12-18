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

void print_error_summary_HIST_WP_TAG_DATASET() {

    //TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j15/Nominal.root");
    //TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j25/Nominal.root");
    //TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j35/Nominal.root");
    //TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j55/Nominal.root");
    //TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j85/Nominal.root");
    //TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j110/Nominal.root");
    //TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j150/Nominal.root");

    //TString histo_name = "WP/HIST";
    //TH1F *l1 = (TH1F*)f1->Get(histo_name);
    //TH1F *l2 = (TH1F*)f1->Get(histo_name);
    //TH1F *l3 = (TH1F*)f2->Get(histo_name);
    //TH1F *l4 = (TH1F*)f3->Get(histo_name);
    //TH1F *l5 = (TH1F*)f4->Get(histo_name);
    //TH1F *l6 = (TH1F*)f4->Get(histo_name);
    //TH1F *l7 = (TH1F*)f5->Get(histo_name);
    //TH1F *l8 = (TH1F*)f6->Get(histo_name);
    //TH1F *l9 = (TH1F*)f7->Get(histo_name);

    //for BT studies, use a separate output for each bin
    TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt20to30_mu4j15/Nominal.root");
    TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt30to40_mu4j15/Nominal.root");
    TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt40to50_mu4j25/Nominal.root");
    TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt50to70_mu4j35/Nominal.root");
    TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt70to90_mu4j55/Nominal.root");
    TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt90to110_mu4j55/Nominal.root");
    TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt110to140_mu6j85/Nominal.root");
    TFile *f8 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt140to170_mu6j110/Nominal.root");
    TFile *f9 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/jpt170to200_mu6j150/Nominal.root");

    TString histo_name = "WP/HIST";
    TH1F *l1 = (TH1F*)f1->Get(histo_name);
    TH1F *l2 = (TH1F*)f2->Get(histo_name);
    TH1F *l3 = (TH1F*)f3->Get(histo_name);
    TH1F *l4 = (TH1F*)f4->Get(histo_name);
    TH1F *l5 = (TH1F*)f5->Get(histo_name);
    TH1F *l6 = (TH1F*)f6->Get(histo_name);
    TH1F *l7 = (TH1F*)f7->Get(histo_name);
    TH1F *l8 = (TH1F*)f8->Get(histo_name);
    TH1F *l9 = (TH1F*)f9->Get(histo_name);

    float b_val_1 = l1->GetBinError(1);
    float b_val_2 = l2->GetBinError(2);
    float b_val_3 = l3->GetBinError(3);
    float b_val_4 = l4->GetBinError(4);
    float b_val_5 = l5->GetBinError(5);
    float b_val_6 = l6->GetBinError(6);
    float b_val_7 = l7->GetBinError(7);
    float b_val_8 = l8->GetBinError(8);
    float b_val_9 = l9->GetBinError(9);        

    cout << "HIST Error for WP DATASET" << endl;
    cout <<  b_val_1 << endl;
    cout <<  b_val_2 << endl;
    cout <<  b_val_3 << endl;
    cout <<  b_val_4 << endl;
    cout <<  b_val_5 << endl;
    cout <<  b_val_6 << endl;
    cout <<  b_val_7 << endl;
    cout <<  b_val_8 << endl;
    cout <<  b_val_9 << endl;

}



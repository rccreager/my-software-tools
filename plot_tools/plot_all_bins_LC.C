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

void plot_all_bins_LC_WP_TAG_DATASET() {

    

    TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j15/Nominal.root");
    TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j25/Nominal.root");
    TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j35/Nominal.root");
    TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j55/Nominal.root");
    TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j85/Nominal.root");
    TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j110/Nominal.root");
    TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j150/Nominal.root");

    TH1F *h1 = (TH1F*)f1->Get("WP/jpt20to30WP/udsFrac_TAG");    
    TH1F *h2 = (TH1F*)f1->Get("WP/jpt30to40WP/udsFrac_TAG");  
    TH1F *h3 = (TH1F*)f2->Get("WP/jpt40to50WP/udsFrac_TAG");  
    TH1F *h4 = (TH1F*)f3->Get("WP/jpt50to70WP/udsFrac_TAG");  
    TH1F *h5 = (TH1F*)f4->Get("WP/jpt70to90WP/udsFrac_TAG");  
    TH1F *h6 = (TH1F*)f4->Get("WP/jpt90to110WP/udsFrac_TAG");  
    TH1F *h7 = (TH1F*)f5->Get("WP/jpt110to140WP/udsFrac_TAG");  
    TH1F *h8 = (TH1F*)f6->Get("WP/jpt140to170WP/udsFrac_TAG");  
    TH1F *h9 = (TH1F*)f7->Get("WP/jpt170to200WP/udsFrac_TAG");  

    int lc_bin_1 = h1->FindFirstBinAbove(0.5);
    int lc_bin_2 = h2->FindFirstBinAbove(0.5);
    int lc_bin_3 = h3->FindFirstBinAbove(0.5);
    int lc_bin_4 = h4->FindFirstBinAbove(0.5);
    int lc_bin_5 = h5->FindFirstBinAbove(0.5);
    int lc_bin_6 = h6->FindFirstBinAbove(0.5);
    int lc_bin_7 = h7->FindFirstBinAbove(0.5);
    int lc_bin_8 = h8->FindFirstBinAbove(0.5);
    int lc_bin_9 = h9->FindFirstBinAbove(0.5); 

    float lc_ratio_1 = h1->GetBinCenter(lc_bin_1);
    float lc_ratio_2 = h2->GetBinCenter(lc_bin_2);
    float lc_ratio_3 = h3->GetBinCenter(lc_bin_3);
    float lc_ratio_4 = h4->GetBinCenter(lc_bin_4);
    float lc_ratio_5 = h5->GetBinCenter(lc_bin_5);
    float lc_ratio_6 = h6->GetBinCenter(lc_bin_6);
    float lc_ratio_7 = h7->GetBinCenter(lc_bin_7);
    float lc_ratio_8 = h8->GetBinCenter(lc_bin_8);
    float lc_ratio_9 = h9->GetBinCenter(lc_bin_9);

    TCanvas *cst = new TCanvas("LCRatio","LC Ratio, WP, TAG, DATASET",5);
    Float_t bins[12] = { 0, 20, 30, 40, 50, 70, 90, 110, 140, 170, 200, 220};
    Int_t  numBins = 11;
    
    TH1F* h = new TH1F("LCRatio","LC Ratio, WP, TAG, DATASET", numBins, bins);
    h->SetBinContent(1,0);
    h->SetBinContent(2,lc_ratio_1);
    h->SetBinContent(3,lc_ratio_2);
    h->SetBinContent(4,lc_ratio_3);
    h->SetBinContent(5,lc_ratio_4);
    h->SetBinContent(6,lc_ratio_5);
    h->SetBinContent(7,lc_ratio_6);
    h->SetBinContent(8,lc_ratio_7);
    h->SetBinContent(9,lc_ratio_8);
    h->SetBinContent(10,lc_ratio_9);
    h->SetBinContent(11,0);

    h->SetMarkerStyle(2);
    h->SetMarkerColor(kViolet);
    h->SetLineColor(kViolet);
    h->SetFillColor(kViolet);
    h->SetFillStyle(3354);
    h->SetLineWidth(2);
    //h->SetEntries(1);
    h->Draw();
    cst->Print("lc_ratio_WP_TAG_DATASET.pdf");
}



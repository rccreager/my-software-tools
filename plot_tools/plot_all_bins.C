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

void plot_all_bins_WP_TAG_DATASET() {

    TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j15/Nominal.root");
    TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j25/Nominal.root");
    TFile *f3 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j35/Nominal.root");
    TFile *f4 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu4j55/Nominal.root");
    TFile *f5 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j85/Nominal.root");
    TFile *f6 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j110/Nominal.root");
    TFile *f7 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/results_DATASET/mu6j150/Nominal.root");

    TH1F *l1 = (TH1F*)f1->Get("WP/jpt20to30WP/light-Fraction_TAG");    
    TH1F *l2 = (TH1F*)f1->Get("WP/jpt30to40WP/light-Fraction_TAG");  
    TH1F *l3 = (TH1F*)f2->Get("WP/jpt40to50WP/light-Fraction_TAG");  
    TH1F *l4 = (TH1F*)f3->Get("WP/jpt50to70WP/light-Fraction_TAG");  
    TH1F *l5 = (TH1F*)f4->Get("WP/jpt70to90WP/light-Fraction_TAG");  
    TH1F *l6 = (TH1F*)f4->Get("WP/jpt90to110WP/light-Fraction_TAG");  
    TH1F *l7 = (TH1F*)f5->Get("WP/jpt110to140WP/light-Fraction_TAG");  
    TH1F *l8 = (TH1F*)f6->Get("WP/jpt140to170WP/light-Fraction_TAG");  
    TH1F *l9 = (TH1F*)f7->Get("WP/jpt170to200WP/light-Fraction_TAG");  

    TH1F *c1 = (TH1F*)f1->Get("WP/jpt20to30WP/c-Fraction_TAG");
    TH1F *c2 = (TH1F*)f1->Get("WP/jpt30to40WP/c-Fraction_TAG");
    TH1F *c3 = (TH1F*)f2->Get("WP/jpt40to50WP/c-Fraction_TAG");
    TH1F *c4 = (TH1F*)f3->Get("WP/jpt50to70WP/c-Fraction_TAG");
    TH1F *c5 = (TH1F*)f4->Get("WP/jpt70to90WP/c-Fraction_TAG");
    TH1F *c6 = (TH1F*)f4->Get("WP/jpt90to110WP/c-Fraction_TAG");
    TH1F *c7 = (TH1F*)f5->Get("WP/jpt110to140WP/c-Fraction_TAG");
    TH1F *c8 = (TH1F*)f6->Get("WP/jpt140to170WP/c-Fraction_TAG");
    TH1F *c9 = (TH1F*)f7->Get("WP/jpt170to200WP/c-Fraction_TAG");

    TH1F *b1 = (TH1F*)f1->Get("WP/jpt20to30WP/b-Fraction_TAG");
    TH1F *b2 = (TH1F*)f1->Get("WP/jpt30to40WP/b-Fraction_TAG");
    TH1F *b3 = (TH1F*)f2->Get("WP/jpt40to50WP/b-Fraction_TAG");
    TH1F *b4 = (TH1F*)f3->Get("WP/jpt50to70WP/b-Fraction_TAG");
    TH1F *b5 = (TH1F*)f4->Get("WP/jpt70to90WP/b-Fraction_TAG");
    TH1F *b6 = (TH1F*)f4->Get("WP/jpt90to110WP/b-Fraction_TAG");
    TH1F *b7 = (TH1F*)f5->Get("WP/jpt110to140WP/b-Fraction_TAG");
    TH1F *b8 = (TH1F*)f6->Get("WP/jpt140to170WP/b-Fraction_TAG");
    TH1F *b9 = (TH1F*)f7->Get("WP/jpt170to200WP/b-Fraction_TAG");

    //TH1F *l1 = (TH1F*)f1->Get("WP/measuredBEfficiencies");
    //TH1F *l2 = (TH1F*)f1->Get("WP/measuredBEfficiencies");
    //TH1F *l3 = (TH1F*)f2->Get("WP/measuredBEfficiencies");
    //TH1F *l4 = (TH1F*)f3->Get("WP/measuredBEfficiencies");
    //TH1F *l5 = (TH1F*)f4->Get("WP/measuredBEfficiencies");
    //TH1F *l6 = (TH1F*)f4->Get("WP/measuredBEfficiencies");
    //TH1F *l7 = (TH1F*)f5->Get("WP/measuredBEfficiencies");
    //TH1F *l8 = (TH1F*)f6->Get("WP/measuredBEfficiencies");
    //TH1F *l9 = (TH1F*)f7->Get("WP/measuredBEfficiencies");
    //
    //TH1F *c1 = (TH1F*)f1->Get("WP/measuredBEfficiencies");
    //TH1F *c2 = (TH1F*)f1->Get("WP/measuredBEfficiencies");
    //TH1F *c3 = (TH1F*)f2->Get("WP/measuredBEfficiencies");
    //TH1F *c4 = (TH1F*)f3->Get("WP/measuredBEfficiencies");
    //TH1F *c5 = (TH1F*)f4->Get("WP/measuredBEfficiencies");
    //TH1F *c6 = (TH1F*)f4->Get("WP/measuredBEfficiencies");
    //TH1F *c7 = (TH1F*)f5->Get("WP/measuredBEfficiencies");
    //TH1F *c8 = (TH1F*)f6->Get("WP/measuredBEfficiencies");
    //TH1F *c9 = (TH1F*)f7->Get("WP/measuredBEfficiencies");
    //
    //TH1F *b1 = (TH1F*)f1->Get("WP/measuredBEfficiencies");
    //TH1F *b2 = (TH1F*)f1->Get("WP/measuredBEfficiencies");
    //TH1F *b3 = (TH1F*)f2->Get("WP/measuredBEfficiencies");
    //TH1F *b4 = (TH1F*)f3->Get("WP/measuredBEfficiencies");
    //TH1F *b5 = (TH1F*)f4->Get("WP/measuredBEfficiencies");
    //TH1F *b6 = (TH1F*)f4->Get("WP/measuredBEfficiencies");
    //TH1F *b7 = (TH1F*)f5->Get("WP/measuredBEfficiencies");
    //TH1F *b8 = (TH1F*)f6->Get("WP/measuredBEfficiencies");
    //TH1F *b9 = (TH1F*)f7->Get("WP/measuredBEfficiencies");

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

    int c_bin_1 = c1->FindFirstBinAbove(0.5);
    int c_bin_2 = c2->FindFirstBinAbove(0.5);
    int c_bin_3 = c3->FindFirstBinAbove(0.5);
    int c_bin_4 = c4->FindFirstBinAbove(0.5);
    int c_bin_5 = c5->FindFirstBinAbove(0.5);
    int c_bin_6 = c6->FindFirstBinAbove(0.5);
    int c_bin_7 = c7->FindFirstBinAbove(0.5);
    int c_bin_8 = c8->FindFirstBinAbove(0.5);
    int c_bin_9 = c9->FindFirstBinAbove(0.5); 

    float c_val_1 = c1->GetBinCenter(c_bin_1);
    float c_val_2 = c2->GetBinCenter(c_bin_2);
    float c_val_3 = c3->GetBinCenter(c_bin_3);
    float c_val_4 = c4->GetBinCenter(c_bin_4);
    float c_val_5 = c5->GetBinCenter(c_bin_5);
    float c_val_6 = c6->GetBinCenter(c_bin_6);
    float c_val_7 = c7->GetBinCenter(c_bin_7);
    float c_val_8 = c8->GetBinCenter(c_bin_8);
    float c_val_9 = c9->GetBinCenter(c_bin_9);

    int b_bin_1 = b1->FindFirstBinAbove(0.5);
    int b_bin_2 = b2->FindFirstBinAbove(0.5);
    int b_bin_3 = b3->FindFirstBinAbove(0.5);
    int b_bin_4 = b4->FindFirstBinAbove(0.5);
    int b_bin_5 = b5->FindFirstBinAbove(0.5);
    int b_bin_6 = b6->FindFirstBinAbove(0.5);
    int b_bin_7 = b7->FindFirstBinAbove(0.5);
    int b_bin_8 = b8->FindFirstBinAbove(0.5);
    int b_bin_9 = b9->FindFirstBinAbove(0.5); 

    float b_val_1 = b1->GetBinCenter(b_bin_1);
    float b_val_2 = b2->GetBinCenter(b_bin_2);
    float b_val_3 = b3->GetBinCenter(b_bin_3);
    float b_val_4 = b4->GetBinCenter(b_bin_4);
    float b_val_5 = b5->GetBinCenter(b_bin_5);
    float b_val_6 = b6->GetBinCenter(b_bin_6);
    float b_val_7 = b7->GetBinCenter(b_bin_7);
    float b_val_8 = b8->GetBinCenter(b_bin_8);
    float b_val_9 = b9->GetBinCenter(b_bin_9);
    
    cout << "bin1: " << b_val_1 << endl;
    cout << "bin2: " << b_val_2 << endl;
    cout << "bin3: " << b_val_3 << endl;
    cout << "bin4: " << b_val_4 << endl;
    cout << "bin5: " << b_val_5 << endl;
    cout << "bin6: " << b_val_6 << endl;
    cout << "bin7: " << b_val_7 << endl;
    cout << "bin8: " << b_val_8 << endl;
    cout << "bin9: " << b_val_9 << endl;

    float norm_1 = l_val_1 + c_val_1 + b_val_1;
    float norm_2 = l_val_2 + c_val_2 + b_val_2;
    float norm_3 = l_val_3 + c_val_3 + b_val_3;
    float norm_4 = l_val_4 + c_val_4 + b_val_4;
    float norm_5 = l_val_5 + c_val_5 + b_val_5;
    float norm_6 = l_val_6 + c_val_6 + b_val_6;
    float norm_7 = l_val_7 + c_val_7 + b_val_7;
    float norm_8 = l_val_8 + c_val_8 + b_val_8;
    float norm_9 = l_val_9 + c_val_9 + b_val_9;

    TCanvas *cst = new TCanvas("BinStack","BinStack",5);
    Float_t bins[12] = { 0, 20, 30, 40, 50, 70, 90, 110, 140, 170, 200, 220};
    Int_t  numBins = 11;
    
    TH1F* l = new TH1F("l","Breakdown per Bin, WP, TAG, DATASET", numBins, bins);
    l->SetBinContent(1,0);
    l->SetBinContent(2,l_val_1 / norm_1); 
    l->SetBinContent(3,l_val_2 / norm_2); 
    l->SetBinContent(4,l_val_3 / norm_3);
    l->SetBinContent(5,l_val_4 / norm_4);
    l->SetBinContent(6,l_val_5 / norm_5);
    l->SetBinContent(7,l_val_6 / norm_6);
    l->SetBinContent(8,l_val_7 / norm_7);
    l->SetBinContent(9,l_val_8 / norm_8);
    l->SetBinContent(10,l_val_9 / norm_9);
    l->SetBinContent(11,0);

    l->SetMarkerStyle(2);
    l->SetMarkerColor(632);
    l->SetLineColor(632);
    l->SetFillColor(632);
    l->SetFillStyle(3354);
    l->SetLineWidth(2);
    //l->Draw();

    TH1F* c = new TH1F("c","Breakdown per Bin, WP, TAG, DATASET", numBins, bins);
    c->SetBinContent(1,0);
    c->SetBinContent(2,c_val_1 / norm_1);
    c->SetBinContent(3,c_val_2 / norm_2);
    c->SetBinContent(4,c_val_3 / norm_3);
    c->SetBinContent(5,c_val_4 / norm_4);
    c->SetBinContent(6,c_val_5 / norm_5);
    c->SetBinContent(7,c_val_6 / norm_6);
    c->SetBinContent(8,c_val_7 / norm_7);
    c->SetBinContent(9,c_val_8 / norm_8);
    c->SetBinContent(10,c_val_9 / norm_9);
    c->SetBinContent(11,0);

    c->SetMarkerStyle(2);
    c->SetMarkerColor(600);
    c->SetLineColor(600);
    c->SetFillColor(600);
    c->SetFillStyle(3354);
    c->SetLineWidth(2);
    //c->Draw();

    TH1F* b = new TH1F("b","Breakdown per Bin, WP, TAG, DATASET", numBins, bins);
    b->SetBinContent(1,0);
    b->SetBinContent(2,b_val_1 / norm_1);
    b->SetBinContent(3,b_val_2 / norm_2);
    b->SetBinContent(4,b_val_3 / norm_3);
    b->SetBinContent(5,b_val_4 / norm_4);
    b->SetBinContent(6,b_val_5 / norm_5);
    b->SetBinContent(7,b_val_6 / norm_6);
    b->SetBinContent(8,b_val_7 / norm_7);
    b->SetBinContent(9,b_val_8 / norm_8);
    b->SetBinContent(10,b_val_9 / norm_9);
    b->SetBinContent(11,0);

    b->SetMarkerStyle(2);
    b->SetMarkerColor(91);
    b->SetLineColor(91);
    b->SetFillColor(91);
    b->SetFillStyle(3354);
    b->SetLineWidth(2);
    //b->Draw();


    THStack *stack = new THStack("myStack","Breakdown per Bin, WP, TAG, DATASET");
    stack->Add(l);
    stack->Add(c);
    stack->Add(b);

    stack->Draw();    

    cst->Print("fit_stack_WP_TAG_DATASET.pdf");
}



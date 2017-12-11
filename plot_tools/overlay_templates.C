#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBox.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>
using namespace std;


void overlay_templates() {
    
    TFile *f1 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/templates_new_tuples_old_BT/427034_Nominal_mu6j150_Templates_merged.root");
    TFile *f2 = TFile::Open("/Users/rcreager/Dropbox/Local_Macbook_files/fitter_from_penn/templates_old_tuples_old_BT/427034_Nominal_mu6j150_Templates_merged.root");

    TList *list1 = (TList*)f1->Get("pTrel");
    TList *list2 = (TList*)f2->Get("pTrel");

    TH1D *h1 = (TH1D*)list1->FindObject("pTrel|jpt170to200|B|MV2c10at60untag");    
    TH1D *h2 = (TH1D*)list2->FindObject("pTrel|jpt170to200|B|MV2c10at60untag");     

    gStyle->SetOptStat(0);
    h1->SetMarkerColor(kRed);
    h1->SetLineColor(kRed);
    h2->SetMarkerColor(kBlue);
    h2->SetLineColor(kBlue);

    TCanvas *cst = new TCanvas("TCanvas","TCanvas",50,50,70000,70000);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.31, 1, 1.0);
    pad1->SetGridx();         // Vertical grid
    //pad1->SetLogy();
    pad1->Draw();             // Draw the upper pad: pad1
    pad1->cd();               // pad1 becomes the current pad

    h1->Draw("hist");
    h2->Draw("same hist");

    TLegend *leg1 = new TLegend(0.65,0.75,0.9,0.9);
    leg1->AddEntry(h1,"New Tuple Template","F");
    leg1->AddEntry(h2,"Old Tuple Template","F");
    leg1->Draw();
        
    cst->cd();          // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->SetGridx(); // vertical grid
    pad2->Draw();
    pad2->cd();       // pad2 becomes the current pad

    TH1D *ratio = (TH1D*)h1->Clone();
    ratio->Divide(h2);

    TLine *line = new TLine(ratio->GetXaxis()->GetXmin(),1.0,ratio->GetXaxis()->GetXmax(),1.0);
    line->SetLineColor(kRed);
    line->SetLineStyle(2);

    ratio->GetYaxis()->SetTitle("ratio");
    ratio->GetXaxis()->SetLabelSize(0.10);
    ratio->GetYaxis()->SetLabelSize(0.07);
    ratio->SetTitle("");

    ratio->SetMaximum(1.5);    
    ratio->SetStats(0);
    ratio->SetMinimum(0.5);

    ratio->SetMarkerStyle(2);
    ratio->SetMarkerColor(kBlack);
    ratio->SetLineColor(kBlack);
    ratio->GetYaxis()->SetTitle("new / old");
    ratio->GetYaxis()->SetTitleSize(0.10);
    std::string option ("e");
    if (!option.compare("e")) ratio->Sumw2();
    //ratio->SetMaximum(ratio->GetMaximum() * 1.1);
    ratio->Draw("e");       // Draw the ratio plot
    line->Draw();

    cst->Print("template_overlay_pTrel_B_jpt170to200_MV2c20at60untag_427034_mu6j150.pdf");

}

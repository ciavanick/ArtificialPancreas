// File used to analyze the data of Artificial pancreas

void Analysis(TString path = "Insert_tap_2.csv")
{

    gStyle->SetOptFit(0010);
    gStyle->SetStatX(0.9);
    gStyle->SetStatY(0.9);
    gStyle->SetStatW(0.1);
    gStyle->SetStatH(0.05);
    gStyle->SetLabelOffset(1.);
    gStyle->SetLabelFont(72);

    TFile *f = new TFile("graph.root", "read");

    // TTree* t = new TTree("t", "Tree");
    // t->ReadFile(path, "t/D, V");

    // Insert salt from 3.2V
    TCanvas *c1 = new TCanvas("c1", "c1");

    // Retrieve the graph from the root file
    TGraph *g1 = (TGraph *)f->Get("Graph;1");

    // Define the fit function
    TF1 *f_exp1 = new TF1("f_exp1", "[0]*e^(-(x-25)/[1])+[2]", 25, 50);
    f_exp1->SetTitle("Voltage vs time; time (s); Voltage (V)");
    f_exp1->SetParNames("A (V)", "T (s)", "V_{0} (V)");
    f_exp1->SetParameters(0.5, 10, 2.5);

    // fit
    g1->Fit("f_exp1", "S", "", 25, 50);

    // Graph cosmetic
    g1->SetTitle("Insert salt from 3.2V;time (s);Voltage (V)");
    g1->SetMarkerStyle(8);
    g1->SetMarkerColor(kBlack);
    g1->SetMarkerSize(.5);
    g1->SetLineStyle(1);
    g1->SetLineWidth(1.);

    // Legend
    TLegend *leg1 = new TLegend(0.6,0.15,0.85,0.25);
    leg1->AddEntry(g1, "Experimental Data");
    leg1->AddEntry(f_exp1, "Fit V = Ae^{-t/T}+V_{0}");

    // Draw and save
    g1->Draw();
    leg1->Draw("SAME");
    c1->Print("FinalPlots/Insert_salt_from_3_2V.png");

    //----------------------------------------------------------

    // Insert Tap 1
    TCanvas *c2 = new TCanvas("c2", "c2");

    // Retrieve the graph from the root file
    TGraph *g2 = (TGraph *)f->Get("Graph;2");

    // Graph cosmetic
    g2->SetTitle("Insert tap 1;time (s);Voltage (V)");
    g2->SetMarkerStyle(8);
    g2->SetMarkerColor(kBlack);
    g2->SetMarkerSize(.5);
    g2->SetLineStyle(1);
    g2->SetLineWidth(1.);

    // Legend
    TLegend *leg2 = new TLegend(0.6,0.15,0.85,0.25);
    leg2->AddEntry(g2, "Experimental Data");

    // Draw and save
    g2->Draw();
    leg2->Draw("SAME");
    c2->Print("FinalPlots/Insert_tap_1.png");

    //----------------------------------------------------------
    // Insert Tap 2
    TCanvas *c3 = new TCanvas("c3", "c3");

    // Retrieve the graph from the root file
    TGraph *g3 = (TGraph *)f->Get("Graph;3");

    // Define the fit function
    TF1 *f_exp3 = new TF1("f_exp3", "[0]*e^(-(x-113)/[1])+[2]", 113, 126);
    f_exp3->SetParNames("A (V)", "T (s)", "V_{0} (V)");
    f_exp3->SetParameters(0.5, 10, 2.5);

    // fit
    g3->Fit("f_exp3", "S", "", 113, 126);

    // Graph cosmetic
    g3->SetTitle("Tap water insertion, V_{low} = 2.1 V; time (s); Voltage (V)");
    g3->SetMarkerStyle(8);
    g3->SetMarkerColor(kBlack);
    g3->SetMarkerSize(.5);
    g3->SetLineStyle(1);
    g3->SetLineWidth(1.);

    // Legend
    TLegend *leg3 = new TLegend(0.105,0.75,0.33,0.9);
    leg3->AddEntry(g3, "Experimental Data");
    leg3->AddEntry(f_exp3, "Fit V = Ae^{-t/T}+V_{0}");

    // Draw and save
    g3->Draw();
    leg3->Draw("SAME");
    c3->Print("FinalPlots/Insert_tap_2.png");
    //----------------------------------------------------------

    // Insert Salt 3V
    TCanvas *c4 = new TCanvas("c4", "c4");

    // Retrieve the graph from the root file
    TGraph *g4 = (TGraph *)f->Get("Graph;4");

    // Define the fit function
    TF1 *f_exp4 = new TF1("f_exp4", "[0]*e^(-(x-40)/[1])+[2]", 40, 80);
    f_exp4->SetParNames("A (V)", "T (s)", "V_{0} (V)");
    f_exp4->SetParameters(0.5, 10, 2.5);

    // fit
    g4->Fit("f_exp4", "S", "", 40, 80);

    // Graph cosmetic
    g4->SetTitle("Insert salt 3V;time (s);Voltage (V)");
    g4->SetMarkerStyle(8);
    g4->SetMarkerColor(kBlack);
    g4->SetMarkerSize(.5);
    g4->SetLineStyle(1);
    g4->SetLineWidth(1.);

    // Legend
    TLegend *leg4 = new TLegend(0.125,0.13,0.4,0.205);
    leg4->AddEntry(g4, "Experimental Data");
    leg4->AddEntry(f_exp4, "Fit V = Ae^{-t/T}+V_{0}");


    // Draw and save
    g4->Draw();
    leg4->Draw("SAME");
    c4->Print("FinalPlots/Insert_salt_3V.png");
    //----------------------------------------------------------
    // Insert Salt 2.86V
    TCanvas *c5 = new TCanvas("c5", "c5");

    // Retrieve the graph from the root file
    TGraph *g5 = (TGraph *)f->Get("Graph;5");

    // Graph cosmetic
    g5->SetTitle("Insert Salt 2.86V;time (s);Voltage (V)");
    g5->SetMarkerStyle(8);
    g5->SetMarkerColor(kBlack);
    g5->SetMarkerSize(.5);
    g5->SetLineStyle(1);
    g5->SetLineWidth(1.);

    // Legend
    TLegend *leg5 = new TLegend(0.6,0.8,0.875,0.875);
    leg5->AddEntry(g5, "Experimental Data");

    // Draw and save
    g5->Draw();
    leg5->Draw("SAME");
    c5->Print("FinalPlots/Insert_salt_2_86V.png");
    //-----------------------------------------------------------

}

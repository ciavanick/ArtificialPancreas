// File used to analyze the data of Artificial pancreas

void Analysis()
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
    g1->SetTitle("Salt water Insertion, V_{HIGH} = 3.1 V;time (s);Voltage (V)");
    g1->SetMarkerStyle(8);
    g1->SetMarkerColor(kBlack);
    g1->SetMarkerSize(.4);
    g1->SetLineStyle(1);
    g1->SetLineWidth(1.);

    //Threshold line
    TLine *line1 = new TLine(0.,3.1,42.2,3.1);
    line1->SetLineColor(kRed + 2);
    line1->SetLineStyle(2);

    // Legend
    TLegend *leg1 = new TLegend(0.6,0.15,0.85,0.25);
    leg1->AddEntry(g1, "Experimental Data");
    leg1->AddEntry(f_exp1, "Fit V = Ae^{-t/T}+V_{0}");
    leg1->AddEntry(line1, "V_{HIGH} = 3.1V", "l");


    // Draw and save
    g1->Draw();
    line1->Draw("SAME");
    leg1->Draw("SAME");
    c1->Print("FinalPlots/Insert_salt_from_3_2V.png");
    c1->Print("FinalPlots/Insert_salt_from_3_2V.pdf");

    //----------------------------------------------------------

    // Insert Tap 1
    TCanvas *c2 = new TCanvas("c2", "c2");

    // Retrieve the graph from the root file
    TGraph *g2 = (TGraph *)f->Get("Graph;2");

    // Graph cosmetic
    g2->SetTitle("Insert tap 1;time (s);Voltage (V)");
    g2->SetMarkerStyle(8);
    g2->SetMarkerColor(kBlack);
    g2->SetMarkerSize(.4);
    g2->SetLineStyle(1);
    g2->SetLineWidth(1.);

    // Legend
    TLegend *leg2 = new TLegend(0.6,0.15,0.85,0.25);
    leg2->AddEntry(g2, "Experimental Data");

    // Draw and save
    g2->Draw();
    leg2->Draw("SAME");
    c2->Print("FinalPlots/Insert_tap_1.png");
    c2->Print("FinalPlots/Insert_tap_1.pdf");

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
    g3->SetTitle("Tap water insertion, V_{LOW} = 2.1 V; time (s); Voltage (V)");
    g3->SetMarkerStyle(8);
    g3->SetMarkerColor(kBlack);
    g3->SetMarkerSize(.4);
    g3->SetLineStyle(1);
    g3->SetLineWidth(1.);

    //Threshold line
    TLine *line3 = new TLine(72.,2.1,130.,2.1);
    line3->SetLineColor(kRed + 2);
    line3->SetLineStyle(2);

    // Legend
    TLegend *leg3 = new TLegend(0.720,0.6,0.9,0.75);
    leg3->AddEntry(g3, "Exp. Data");
    leg3->AddEntry(f_exp3, "Fit V=Ae^{-t/T}+V_{0}");
    leg3->AddEntry(line3, "V_{LOW} = 2.1V", "l");

    // Draw and save
    g3->Draw();
    line3->Draw("SAME");
    leg3->Draw("SAME");
    c3->Print("FinalPlots/Insert_tap_2.png");
    c3->Print("FinalPlots/Insert_tap_2.pdf");
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
    g4->SetTitle("Salt water insertion, V_{HIGH} = 3 V;time (s);Voltage (V)");
    g4->SetMarkerStyle(8);
    g4->SetMarkerColor(kBlack);
    g4->SetMarkerSize(.4);
    g4->SetLineStyle(1);
    g4->SetLineWidth(1.);

    //Threshold line
    TLine *line4 = new TLine(0.,3.,90.,3.);
    line4->SetLineColor(kRed + 2);
    line4->SetLineStyle(2);

    // Legend
    TLegend *leg4 = new TLegend(0.125,0.13,0.4,0.23);
    leg4->AddEntry(g4, "Experimental Data");
    leg4->AddEntry(f_exp4, "Fit V = Ae^{-t/T}+V_{0}");
    leg4->AddEntry(line4, "V_{HIGH} = 3V","l");


    // Draw and save
    g4->Draw();
    line4->Draw("SAME");
    leg4->Draw("SAME");
    c4->Print("FinalPlots/Insert_salt_3V.png");
    c4->Print("FinalPlots/Insert_salt_3V.pdf");
    //----------------------------------------------------------
    // Insert Salt 2.86V
    TCanvas *c5 = new TCanvas("c5", "c5");

    // Retrieve the graph from the root file
    TGraph *g5 = (TGraph *)f->Get("Graph;5");

    // Graph cosmetic
    g5->SetTitle("Salt water insertion, V_{HIGH} = 2.86 V;time (s);Voltage (V)");
    g5->SetMarkerStyle(8);
    g5->SetMarkerColor(kBlack);
    g5->SetMarkerSize(.4);
    g5->SetLineStyle(1);
    g5->SetLineWidth(1.);

    //Threshold line
    TLine *line5 = new TLine(0.,2.86,70.,2.86);
    line5->SetLineColor(kRed + 2);
    line5->SetLineStyle(2);

    // Legend
    TLegend *leg5 = new TLegend(0.6,0.8,0.875,0.875);
    leg5->AddEntry(g5, "Experimental Data");
    leg5->AddEntry(line5, "V_{HIGH} = 2.86V","l");

    // Draw and save
    g5->Draw();
    line5->Draw("SAME");
    leg5->Draw("SAME");
    c5->Print("FinalPlots/Insert_salt_2_86V.png");
    c5->Print("FinalPlots/Insert_salt_2_86V.pdf");
    //-----------------------------------------------------------

}

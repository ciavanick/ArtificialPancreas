void Allplots(){
    TFile *f = new TFile("graph.root", "read");

    TCanvas *c1 = new TCanvas("c1", "c1");

    //--------------------------------------------------------------------------

    // Retrieve the graph from the root file
    TGraph *g1 = (TGraph *)f->Get("Graph;1");

    // Graph cosmetic
    g1->SetTitle("Salt water Insertion, V_{HIGH} = 3.1 V;time (s);Voltage (V)");
    g1->SetMarkerStyle(8);
    g1->SetMarkerColor(kBlack);
    g1->SetMarkerSize(.4);
    g1->SetLineStyle(1);
    g1->SetLineColor(kBlack);
    g1->SetLineWidth(1.);

    TLine *line1 = new TLine(0.,3.1,80.,3.1);
    line1->SetLineColor(kBlack);
    line1->SetLineStyle(2);
    //--------------------------------------------------------------------------
    // Retrieve the graph from the root file
    TGraph *g3 = (TGraph *)f->Get("Graph;3");

    // Graph cosmetic
    g3->SetTitle("Tap water insertion, V_{LOW} = 2.1 V; time (s); Voltage (V)");
    g3->SetMarkerStyle(8);
    g3->SetMarkerColor(kBlack);
    g3->SetMarkerSize(.4);
    g3->SetLineStyle(1);
    g3->SetLineColor(kBlack);
    g3->SetLineWidth(1.);
    //--------------------------------------------------------------------------
    // Retrieve the graph from the root file
    TGraph *g4 = (TGraph *)f->Get("Graph;4");

    // Graph cosmetic
    g4->SetTitle("Salt water insertion, V_{HIGH} = 3 V;time (s);Voltage (V)");
    g4->SetMarkerStyle(8);
    g4->SetMarkerColor(kRed);
    g4->SetMarkerSize(.4);
    g4->SetLineStyle(1);
    g4->SetLineColor(kRed);
    g4->SetLineWidth(1.);

    TLine *line4 = new TLine(0.,3.,80.,3.);
    line4->SetLineColor(kRed);
    line4->SetLineStyle(2);
    //--------------------------------------------------------------------------
     // Retrieve the graph from the root file
    TGraph *g5 = (TGraph *)f->Get("Graph;5");

    // Graph cosmetic
    g5->SetTitle("Salt water insertion, V_{HIGH} = 2.86 V;time (s);Voltage (V)");
    g5->SetMarkerStyle(8);
    g5->SetMarkerColor(kBlue);
    g5->SetMarkerSize(.4);
    g5->SetLineStyle(1);
    g5->SetLineColor(kBlue);
    g5->SetLineWidth(1.);

    TLine *line5 = new TLine(0.,2.86,80.,2.86);
    line5->SetLineColor(kBlue);
    line5->SetLineStyle(2);
    //--------------------------------------------------------------------------
    TMultiGraph *mg1 = new TMultiGraph("mg1","Salt water insertion;time (s); Voltage (V)");
    mg1->Add(g1);
    //mg1->Add(g3);
    mg1->Add(g4);
    mg1->Add(g5);

    TLegend *leg = new TLegend(0.6,0.65,0.85,0.8);
    leg->AddEntry(g1, "V_{HIGH} = 3.1V");
    leg->AddEntry(g4, "V_{HIGH} = 3V");
    leg->AddEntry(g5, "V_{HIGH} = 2.86V");

    mg1->Draw("apl");
    line1->Draw("SAME");
    line4->Draw("SAME");
    line5->Draw("SAME");
    leg->Draw("Same");
    c1->Print("AllPlots/Insert_salt.png");
}
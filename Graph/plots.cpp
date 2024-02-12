void plots(){
    TFile *f = new TFile("graph.root","read");

    TCanvas *c1 = new TCanvas("c1","c1");
    TGraph *g1 = (TGraph*) f->Get("Graph;1");
    g1->SetTitle("Insert salt from 3.2V;s;V");
    g1->SetMarkerStyle(8);
    g1->SetMarkerColor(kRed + 2);
    g1->SetMarkerSize(0.5);
    g1->SetLineStyle(1);
    g1->SetLineWidth(1.5);
    g1->Draw();

    TCanvas *c2 = new TCanvas("c2","c1");
    TGraph *g2 = (TGraph*) f->Get("Graph;2");
    TGraph *g3 = (TGraph*) f->Get("Graph;3");
    g2->SetTitle("Insert salt from 3.2V;s;V");
    g2->SetMarkerStyle(8);
    g2->SetMarkerColor(kRed + 2);
    g2->SetMarkerSize(0.5);
    g2->SetLineStyle(1);
    g2->SetLineWidth(1.5);
    g2->Draw();
    g1->Draw("SAME");
}
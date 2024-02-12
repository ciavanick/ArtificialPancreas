void fit(){
     TFile *f = new TFile("graph.root","read");

     TGraph *g4 = (TGraph*) f->Get("Graph;1");
     //g4->GetXaxis()->SetRange(80,160);
     TF1* f_exp = new TF1("f_exp", "[0]*e^(-(x-25)/[1])+[2]", 25, 50);
    f_exp->SetTitle("Voltage vs time; time (s); Voltage (V)");
    f_exp->SetParNames("A","T","V_{0}");
    f_exp->SetParameters(0.5,10,2.5);
    g4->Fit("f_exp", "S", "", 25, 50);
    g4->SetMarkerStyle(8);
    g4->SetMarkerColor(kBlack);
    g4->SetMarkerSize(.7);
    g4->SetLineStyle(1);
    g4->SetLineWidth(1.);
     g4->Draw();
}
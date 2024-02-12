// File used to analyze the data of Artificial pancreas

void Analysis(TString path = "Insert_tap_2.csv") {
    
    gStyle->SetOptFit(0010);
    
    // TTree* t = new TTree("t", "Tree");
    // t->ReadFile(path, "t/D, V");
    
    TGraph* g = new TGraph(path, "%lg %lg", ",");
    TF1* f_exp = new TF1("f_exp", "[0]*e^(-(x-113)/[1])+[2]", 113, 126);
    g->SetTitle("Tap water insertion, V_{low} = 2.1 V; time (s); Voltage (V)");
    f_exp->SetParNames("A (V)","T (s)","V_{0} (V)");
    f_exp->SetParameters(0.5,10,2.5);
    g->Fit("f_exp", "S", "", 113, 126);
    
    TLegend* leg = new TLegend();
    leg->AddEntry(g, "Experimental Data");
    leg->AddEntry(f_exp, "Fit V = Ae^{-t/T}+V_{0}");
    
    g->Draw();
    leg->Draw("SAME");
    
}

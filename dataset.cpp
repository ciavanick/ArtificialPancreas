void dataset()
{
    auto fileName = "Insert_Salt_3.1V_from_3.2V.csv";
    TGraph *g1 = new TGraph ("Insert_Salt_3.1V_from_3.2V.csv", "%lg %lg", ",");
    TGraph *g2 = new TGraph ("Insert_tap_1.csv", "%lg %lg", ",");
    TGraph *g3 = new TGraph ("Insert_tap_2.csv", "%lg %lg", ",");
    TGraph *g4 = new TGraph ("Insert_Salt_3V.csv", "%lg %lg", ",");
    TGraph *g5 = new TGraph ("Insert_Salt_2_86V.csv", "%lg %lg", ",");
    //g1->GetXaxis()->SetLimits(50,100);
    //TF1  *f1 = new TF1("f1","(1. - TMath::Exp(-[0]*x))*[1]",9,30);
    //TF1 *f1 = new TF1("f1","[0]*x*sin([1]*x)",-3,3);
    //TF1 *f1 = new TF1("f1","TMath::DiLog([0]x)",9,30);
    //TCanvas* c1 = new TCanvas("c1","c1");
    //f1->SetParameter(0,1.);
    //g1->Fit("expo");
    //f1->Draw();
    //g1->Draw();

    TFile *f = new TFile("graph.root", "recreate");
    g1->Write();
    g2->Write();
    g3->Write();
    g4->Write();
    g5->Write();
    f->Close();
}
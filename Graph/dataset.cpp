void dataset()
{
    auto fileName = "Insert_Salt_3.1V_from_3.2V.csv";
    TGraph *g1 = new TGraph("Insert_Salt_3.1V_from_3.2V.csv", "%lg %lg", ",");
    TGraph *g2 = new TGraph("Insert_tap_1.csv", "%lg %lg", ",");
    TGraph *g3 = new TGraph("Insert_tap_2.csv", "%lg %lg", ",");
    TGraph *g4 = new TGraph("Insert_Salt_3V.csv", "%lg %lg", ",");
    TGraph *g5 = new TGraph("Insert_Salt_2_86V.csv", "%lg %lg", ",");

    TCanvas *c1 = new TCanvas("c1","Insert Salt 3.1V");
    g1->Draw();
    c1->Print("RawPlots/Ins_Salt_3_1V.png");

    TCanvas *c2 = new TCanvas("c2","Insert Tap");
    g2->Draw();
    c2->Print("RawPlots/Ins_Tap_1.png");

    TCanvas *c3 = new TCanvas("c3","Insert Tap");
    g3->Draw();
    c3->Print("RawPlots/Ins_Tap_2.png");

    TCanvas *c4 = new TCanvas("c4","Insert Salt 3V");
    g4->Draw();
    c4->Print("RawPlots/Ins_Salt_3V.png");

    TCanvas *c5 = new TCanvas("c5","Insert Salt 2.86V");
    g5->Draw();
    c5->Print("RawPlots/Ins_Salt_2_86V.png");

    TFile *f = new TFile("graph.root", "recreate");
    g1->Write();
    g2->Write();
    g3->Write();
    g4->Write();
    g5->Write();
    f->Close();
}
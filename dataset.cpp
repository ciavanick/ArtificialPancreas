void dataset()
{
    auto fileName = "Insert_Salt_3.1V_from_3.2V.csv";
    TGraph *g1 = new TGraph ("Insert_Salt_3.1V_from_3.2V.csv", "%lg %lg", ",");
    TGraph *g2 = new TGraph ("Insert_tap_1.csv", "%lg %lg", ",");
    TGraph *g3 = new TGraph ("Insert_tap_2.csv", "%lg %lg", ",");
    TGraph *g4 = new TGraph ("Insert_Salt_3V.csv", "%lg %lg", ",");
    TGraph *g5 = new TGraph ("Insert_Salt_2_86V.csv", "%lg %lg", ",");

    TFile *f = new TFile("graph.root", "recreate");
    g1->Write();
    g2->Write();
    g3->Write();
    g4->Write();
    g5->Write();
    f->Close();
}
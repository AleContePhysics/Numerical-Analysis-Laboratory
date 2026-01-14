#include "EsperimentoPrisma.h"
#include <string>
#include <sstream>
#include <iomanip>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TH2F.h"

int main(){
    TApplication app("app",0,0);
    vector<TH1F>Istogrammi(9);
    vector<TH2F>IstogrammiBi(3);
    vector<TCanvas>Canva(12);
    vector<double>Dev(9);
    vector<double>Mean(9);
    vector<double>P(15);
    EsperimentoPrisma Prisma(1);

    TH1F Grafico1("Distribuzione di Theta0","Theta0",100,1.5694,1.5725);
    Istogrammi[0]=Grafico1;
    TH1F Grafico2("Distribuzione di Theta1","Theta1",100,2.548,2.5502);
    Istogrammi[1]=Grafico2;
    TH1F Grafico3("Distribuzione di Theta2","Theta2",100,2.655,2.6595);
    Istogrammi[2]=Grafico3;
    TH1F Grafico4("Distribuzione di DeltaM1","DeltaM1",100,-0.002,0.002);
    Istogrammi[3]=Grafico4;
    TH1F Grafico5("Distribuzione di DeltaM2","DeltaM2",100,-0.002,0.002);
    Istogrammi[4]=Grafico5;
    TH1F Grafico6("Distribuzione di n1","n1",100,-0.001,0.001);
    Istogrammi[5]=Grafico6;
    TH1F Grafico12("Distribuzione di n2","n2",100,-0.001,0.001);
    Istogrammi[6]=Grafico12;
    TH1F Grafico7("Distribuzione di A","A",100,-0.006,0.006);
    Istogrammi[7]=Grafico7;
    TH1F Grafico8("Distribuzione di B","B",100,-1.*pow(10,-15),1.*pow(10,-15));
    Istogrammi[8]=Grafico8;
    TH2F Grafico9("Residui 2D","Residui delta",100,-0.003,0.003,100,-0.003,0.003);
    IstogrammiBi[0]=Grafico9;
    TH2F Grafico10("Residui n1,n2","Residui n",100,-0.002,0.002,100,-0.001,0.001);
    IstogrammiBi[1]=Grafico10;
    TH2F Grafico11("Residui A e B","Residui",100,-0.005,0.005,100,-1.*pow(10,-15),1.*pow(10,-15));
    IstogrammiBi[2]=Grafico11;
    
    for(unsigned int n=1;n<=10000;n++){

        Prisma.Esegui();
        Prisma.Analizza();
        Istogrammi[0].Fill(Prisma.GetTheta0mis());
        Istogrammi[1].Fill(Prisma.GetTheta1mis());
        Istogrammi[2].Fill(Prisma.GetTheta2mis());
        Istogrammi[3].Fill(Prisma.GetDeltam1mis()-Prisma.GetDeltam1());
        Istogrammi[4].Fill(Prisma.GetDeltam2mis()-Prisma.GetDeltam2());
        Istogrammi[5].Fill(Prisma.Getn1mis()-Prisma.Getn1());
        Istogrammi[6].Fill(Prisma.Getn2mis()-Prisma.Getn2());
        Istogrammi[7].Fill(Prisma.GetAmis()-Prisma.GetA());
        Istogrammi[8].Fill(Prisma.GetBmis()-Prisma.GetB());
        IstogrammiBi[0].Fill(Prisma.GetDeltam1mis()-Prisma.GetDeltam1(),Prisma.GetDeltam2mis()-Prisma.GetDeltam2());
        IstogrammiBi[1].Fill(Prisma.Getn1mis()-Prisma.Getn1(),Prisma.Getn2mis()-Prisma.Getn2());
        IstogrammiBi[2].Fill(Prisma.GetAmis()-Prisma.GetA(),Prisma.GetBmis()-Prisma.GetB());

    }
    
    //statistica//

    cout<<"correlazione fra delta1 e delta2: "<<IstogrammiBi[0].GetCorrelationFactor(1,2)*100.<<" %"<<endl;
    cout<<"correlazione fra n1 e n2: "<<IstogrammiBi[1].GetCorrelationFactor(1,2)*100.<<" %"<<endl;
    cout<<"correlazione fra A e B: "<<IstogrammiBi[2].GetCorrelationFactor(1,2)*100.<<" %"<<endl;
   
    for(unsigned int i=0;i<Istogrammi.size();i++){
        Dev[i]=Istogrammi[i].GetStdDev();
        Mean[i]=Istogrammi[i].GetMean();
    }

    Canva[0].cd();
    Istogrammi[0].Draw();
    Canva[0].Print("Theta/DistribuzioneTheta0.pdf");
    Canva[0].Close();
    Canva[1].cd();
    Istogrammi[1].Draw();
    Canva[1].Print("Theta/DistribuzioneTheta1.pdf");
    Canva[1].Close();
    Canva[2].cd();
    Istogrammi[2].Draw();
    Canva[2].Print("Theta/DistribuzioneTheta2.pdf");
    Canva[2].Close();
    Canva[3].cd();
    Istogrammi[3].Draw();
    Canva[3].Print("DeltaM/DistribuzioneDeltaM1.pdf");
    Canva[3].Close();
    Canva[4].cd();
    Istogrammi[4].Draw();
    Canva[4].Print("DeltaM/DistribuzioneDeltaM2.pdf");
    Canva[4].Close();
    Canva[5].cd();
    IstogrammiBi[0].Draw();
    Canva[5].Print("DeltaM/Residui2D.pdf");
    Canva[5].Close();
    Canva[6].cd();
    Istogrammi[5].Draw();
    Canva[6].Print("n/Distribuzionen1.pdf");
    Canva[6].Close();
    Canva[7].cd();
    Istogrammi[6].Draw();
    Canva[7].Print("n/Distribuzionen2.pdf");
    Canva[7].Close();
    Canva[8].cd();
    IstogrammiBi[1].Draw();
    Canva[8].Print("n/ResiduiN.pdf");
    Canva[8].Close();
    Canva[9].cd();
    Istogrammi[7].Draw();
    Canva[9].Print("Coefficenti/DistribuzioneA.pdf");
    Canva[9].Close();
    Canva[10].cd();
    Istogrammi[8].Draw();
    Canva[10].Print("Coefficenti/DistribuzioneB.pdf");
    Canva[10].Close();
    Canva[11].cd();
    IstogrammiBi[2].Draw();
    Canva[11].Print("Coefficenti/ResiduiAB.pdf");
    Canva[11].Close();
    app.Run();

    return 0;
}
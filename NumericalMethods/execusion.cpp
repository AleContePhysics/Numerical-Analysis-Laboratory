#include"integrali.h"
#include<vector>
#include<fstream>
#include"TApplication.h"
#include"TH1F.h"
#include"TGraph.h"
#include"TCanvas.h"
#include"TAxis.h"

int main(int argc,char** argv){
    if(argc!=3){
        cout<<"struttura file: <"<<argv[0]<<"> <Metodo: HM / Media> <Precisione>"<<endl;
        return -1;
    }
    string Metodo=argv[1];
    if(Metodo!="HM" && Metodo!="Media"){
        cout<<"Metodi accettati: <Metodo: HM / Media>"<<endl;
        return -1;
    }
    double h=atof(argv[2]);
    TApplication app("app",0,0);
    vector<int>N{100,500,1000,5000,10000,50000,100000};
    vector<TH1F>Istogrammi;
    vector<TCanvas>Canva;
    string title,titler;
    TGraph Grafico;
    double appo=0;

    for(unsigned int n=1;n<=N.size();n++){
        ifstream in;
        if(Metodo=="Media"){
            in.open("Integrali/Media_N="+to_string(N[n-1])+".dat");
            title="Media_N="+to_string(N[n-1])+"";
            titler="Istogrammi/Media_N="+to_string(N[n-1])+".pdf";
        } else {
            in.open("Integrali/HM_N="+to_string(N[n-1])+".dat");
            title="HM_N="+to_string(N[n-1])+"";
            titler="Istogrammi/HM_N="+to_string(N[n-1])+".pdf";
        }
        TH1F isto(title.c_str(),title.c_str(),100,1.8,2.2);
        while(in.eof()==false){
            double k;
            in>>k;
            isto.Fill(k);
        }
        TCanvas c("Grafico","grafico",800,600);
        c.cd();
        isto.GetXaxis()->SetTitle("Integrale");
        isto.Draw();
        Grafico.SetPoint(n,N[n-1],isto.GetStdDev());
        c.Print(titler.c_str());
        in.close();
        Istogrammi.push_back(isto);
    }
    TCanvas c1;
    c1.cd();
    Grafico.GetXaxis()->SetTitle("N estrazioni");
    Grafico.GetYaxis()->SetTitle("Errore");
    c1.SetGrid();
    c1.SetLogx();
    c1.SetLogy();
    Grafico.GetYaxis()->SetRangeUser(10E-4,10E-2);
    Grafico.GetXaxis()->SetRangeUser(100,10E5);
    Grafico.Draw("ALP");
    Grafico.SetMarkerStyle(20);
    if(Metodo=="Media"){
        Grafico.SetTitle("Errore Metodo Media");
        c1.Print("ErroreMedia.pdf");
        double j=pow(Istogrammi[N.size()-1].GetStdDev(),2)*N[N.size()-1]/pow(h,2);
        cout<<"Per avere "<<h<<" di precisione servono: "<<j<<" punti"<<endl;
    }else {
        Grafico.SetTitle("Errore Metodo HM");
        c1.Print("ErroreHM.pdf");
        double j=pow(Istogrammi[N.size()-1].GetStdDev(),2)*N[N.size()-1]/pow(h,2);
        cout<<"Per avere "<<h<<" di precisione servono: "<<j<<" punti"<<endl;
    }
    app.Run();
}

exclu(){

  TCanvas* can      = new TCanvas("can", "can", 40, 40, 800, 800);
  TCanvas* cancan = new TCanvas("cancan", "cancan", 40, 40, 800, 800);
  can      ->cd();
  gStyle   ->SetOptStat(0);
  TH2F*    frame2   = new TH2F("frame2", "exclusion #varepsilon^{2} versus m_{Z_{d}}, #delta = 0.00003", 200, 0.003, 1., 200, 0.00000000005, 0.0001);
  frame2   ->GetXaxis()->SetTitle("m_{Z_{d}} (GeV)  ");
  frame2   ->GetYaxis()->SetTitle("#varepsilon^{2}     ");
  frame2   ->Draw();
  cancan   ->cd();
  gStyle   ->SetOptStat(0);
  TH2F*    frame22  = new TH2F("frame22", "exclusion #varepsilon^{2} versus #delta, m_{Z_{d}} = 75 MeV", 200, 0.0001, 1., 200, 0.00000000005, 0.0001);
  frame22  ->GetYaxis()->SetTitle("#varepsilon^{2}     ");
  frame22  ->GetXaxis()->SetTitle("#delta     ");
  frame22  ->Draw();
  //Float_t  N        = 0.01;       //Percent difference of asymmetry ratios, divided by 100
  Float_t  N;
  Float_t  sigmas[] = {0.024, 0.048, 0.12};
  Float_t  sin2th   = 0.2397;     //sin^2(theta_W) of Weinberg angle
  Float_t  Q_W      = 1 - 4 * sin2th; //Q weak
  Float_t  delta2   = 0.00003;    //Model dependant parameter
  Float_t  delta    = TMath::Sqrt(delta2);     //Model dependant parameter
  Float_t  m_z      = 91.1876;    //GeV
  Float_t  Q2       = 0.0056;     //GeV^2
  Float_t  cos2th   = 1 - sin2th;
  Float_t  cotth    = TMath::Sqrt( cos2th / sin2th );
    
  Float_t  m_z_d    = 0.075;
  
  
  TString  formula  = " %f * ( %f + x * x ) / x ";
  for(Int_t i = 0; i < 3; i++ ){
    //Float_t  N        = 0.01 * ( i + 1 );
    N = sigmas[i];
    Float_t  prefac   = N * Q_W / ( delta * m_z * cotth * 4 * sin2th);
    Float_t  prefac2  = prefac * prefac;
    
    TF1*     epsilon  = new TF1(Form("epsilon%d", i), Form(" %f * ( %f + x * x ) / x ", prefac, Q2), 0.0, 1.0);
    TF1*     epsilon2 = new TF1(Form("epsilon2%d", i), Form(" %lf * ( %f + x * x ) * ( %f + x * x ) / x / x / 10000. ", prefac2 * 10000. , Q2, Q2), 0.00000001, 1.0);
    
    can->cd();
    epsilon2 -> SetLineColor( i + 1 );
    epsilon2 -> Draw("SAME");
    Float_t  prefac_  = N * Q_W / ( m_z * cotth * 4 * sin2th) * ( Q2 + m_z_d * m_z_d ) / m_z_d;
    Float_t  prefac_2 = prefac_ * prefac_;
    TF1*     epsilon22= new TF1(Form("epsilon22%d", i), Form(" %f / x / x / 10000000000.", prefac_2 * 10000000000.), 0.0, 1.0);

    cancan->cd();
    epsilon22 -> SetLineColor( i + 1 );
    epsilon22 ->Draw("SAME");
   }

  can->cd();
  can       -> SetLogx();
  can       -> SetLogy();
  TPaveText* texty = new TPaveText(.8,.8,.9,.9,"blNDC");
  //texty     ->AddText("1%")->SetTextColor(1);
  //texty     ->AddText("2%")->SetTextColor(2);
  //texty     ->AddText("3%")->SetTextColor(3);
  texty     ->AddText("1 #sigma")->SetTextColor(1);
  texty     ->AddText("2 #sigma")->SetTextColor(2);
  texty     ->AddText("5 #sigma")->SetTextColor(3);
  texty     ->SetBorderSize(1); 
  texty     ->Draw();
  gPad      ->Update();

  can->SaveAs("exclu.png");

  cancan    -> SetLogx();
  cancan    -> SetLogy();
 
}

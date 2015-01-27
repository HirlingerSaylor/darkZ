correction(){

  Float_t APV_ar[200];
  Float_t m_z_d_ar[200];

  for(Int_t i = 0; i < 200; i ++ ) {
    Float_t m_z_d  =  0.005 * i + 0.000001;              //GeV
    Float_t m_z    = 91.187;              //GeV
    Float_t m      =  0.000511;           //GeV
    Float_t M      =  0.938;              //GeV
    
    Float_t delta  = 0.001;
    Float_t eps    = 0.002;
    Float_t eps_z  = m_z_d * delta / m_z;
    Float_t Q2     = 0.0080;               //GeV^2
    Float_t sinth2 = 0.2397;
    Float_t GF     = .0000116637;         //GeV^-2
    
    Float_t k_d    = 1. - ( eps / eps_z ) * delta * delta * TMath::Sqrt( 1. / sinth2 - 1. ) * ( m_z_d * m_z_d / ( Q2 + m_z_d * m_z_d ) );
    Float_t QWe_d  = 1. - 4. * k_d * sinth2;
    
    Float_t alpha = 1. / 137.;
    Float_t E     = 11.;
    Float_t y     = Q2 / 2. / M / E;
    
    Float_t APV    = m * E * GF / TMath::Sqrt( 2 ) / TMath::Pi() / alpha * 2 * y * ( 1 - y ) / ( 1 + TMath::Power(y, 4) + TMath::Power( ( 1 - y ), 4) ) * QWe_d;
    APV_ar[i]   = APV;
    m_z_d_ar[i] = m_z_d;
    cout << APV << endl;
  }

  TGraph *gr = new TGraph(200, m_z_d_ar, APV_ar);
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(.5);
  gr->SetTitle("APV(m_{z_d})");
  gr->GetXaxis()->SetTitle("m_z_d");
  gr->GetYaxis()->SetTitle("APV(m_z_d)");
  gr->Draw("AP");

}

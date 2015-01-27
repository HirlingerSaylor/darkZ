Q2(){
  TFile* infile = new TFile("outfile2.root", "READ");
  infile->cd();
  Float_t fitconstants[4][11] = { { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. },  
				  { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. },  
				  { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. },  
				  { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. } };
  Float_t intconstants[4][11] = { { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. },  
				  { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. },  
				  { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. },  
				  { 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0. } };

  Float_t mins[4] = {0.935, 0.935, 0.960, 0.960};
  Float_t maxs[4] = {1.100, 1.040, 1.075, 1.100};
  Float_t hist_min = 0.6;
  Float_t hist_max = 1.5;
  Float_t nbins    = 1000;
  Float_t delta    = ( hist_max - hist_min ) / nbins;
  
  Int_t minbin[4];
  Int_t maxbin[4];

  for(Int_t i = 0; i < 4; i++){
    minbin[i] = TMath::FloorNint( ( mins[i] - hist_min ) / delta );
    maxbin[i] = TMath::FloorNint( ( maxs[i] - hist_min ) / delta );
    cout << minbin[i] << " " << maxbin[i] << endl;
  }

  //TString mass[12] = { "0 MeV", "50 MeV", "75 MeV", "100 MeV", "150 MeV", "200 MeV", "250 MeV",
  //"300 MeV", "350 MeV", "open", "transition", "closed"};
  /*
rootfiles5/moller5_59.375.root
rootfiles5/moller5_62.5.root
rootfiles5/moller5_65.625.root
rootfiles5/moller5_68.75.root
rootfiles5/moller5_71.875.root
rootfiles5/moller5_75.root
rootfiles5/moller5_78.125.root
rootfiles5/moller5_81.25.root
rootfiles5/moller5_84.375.root
rootfiles5/moller5_87.5.root
rootfiles5/moller5_90.625.root
rootfiles5/moller5_93.75.root
rootfiles5/moller5_96.875.root
rootfiles5/moller5_100.root
rootfiles5/moller5_112.5.root
*/
  TString mass[] = {  "0.0 MeV", "59.375 MeV" , "62.5   MeV" , 
		      "65.625 MeV" , "68.75  MeV" ,
		      "71.875 MeV" , "75     MeV", "78.125 MeV",
		      "81.25  MeV" , "84.375 MeV",
		      "87.5   MeV" , "90.625 MeV",
		      "93.75  MeV" , "96.875 MeV",
		      "100.0 MeV", "112.5 MeV",
		      "125 MeV"  };
  
  TString histname[4] = { "rate(Q2) @ ", "rate(#theta) @ ", "rate(E) @ ", "A_{PV}(r) @ "};
  //Float_t masses[9] = {   0.,  50.,  75., 100., 150., 200.,
  //250., 300., 350.};
  float masses[] = {0., 59.375 , 62.5   , 
		    65.625 , 68.75  ,
		    71.875 , 75     , 78.125,
		    81.25  , 84.375 ,
		    87.5   , 90.625 ,
		    93.75  , 96.875 ,
		    100.0  , 112.5 ,
		    125.  };
  //150., 200.,
  //250., 300., 350.};
  
  TH1F* anorm[4];
  TF1*  f[11][4];
  
  TCanvas* can1 = new TCanvas("can1", "can1",  20,  20, 2000, 700);
  TCanvas* can2 = new TCanvas("can2", "can2",  40,  40, 2000, 700);
  TCanvas* can3 = new TCanvas("can3", "can3",  60,  60, 2000, 700);
  TCanvas* can4 = new TCanvas("can4", "can4",  80,  80, 2000, 700);
  TCanvas* can5 = new TCanvas("can5", "can5", 100, 100, 2000, 700);
  TCanvas* can6 = new TCanvas("can6", "can6", 120, 120, 2000, 700);
  can1->Divide( 7, 2 );
  can2->Divide( 7, 2 );
  can3->Divide( 7, 2 );
  can4->Divide( 7, 2 );
  can5->Divide( 7, 2 );
  for( Int_t i = 0; i < 11; i++ ) {
    
    for(Int_t j = 0; j < 4; j++) {
      can1->cd( i + 1 );
      TH1F* dummy1 = (TH1F*)infile->Get(Form("Q2_hist%d%d", i, j))->Clone();
      dummy1->GetXaxis()->SetRangeUser(0., 0.004);
      dummy1->SetTitle(histname[0] + mass[i]);
      dummy1->GetXaxis()->SetTitle("Q^{2} (GeV^{2})");
      dummy1->GetYaxis()->SetTitle("rate (arb. units)");
      //dummy1->GetYaxis()->SetRangeUser(0., 4500000000);
      //dummy1->SetBinContent(1, 0);
      if( j == 0 ) {
	dummy1->Draw();
	dummy1->SetLineColor(1);
      } else if ( j == 1 ) {
	dummy1->SetLineColor(2);
	dummy1->Draw("SAME");
	can1->cd( 12 );
	dummy1->SetTitle("");
	dummy1->Draw("SAME");
      } else if ( j == 2 ) {
	dummy1->SetLineColor(3);
	dummy1->Draw("SAME");
	can1->cd( 13 );
	dummy1->SetTitle("");
	dummy1->Draw("SAME");
      }else if ( j == 3 ) {
	dummy1->SetLineColor(4);
	dummy1->Draw("SAME");
	can1->cd( 14 );
	dummy1->SetTitle("");
	dummy1->Draw("SAME");
      }
      
      can2->cd( i + 1 );
      TH1F* dummy2 = (TH1F*)infile->Get(Form("th_hist%d%d", i, j))->Clone();
      dummy2->SetTitle(histname[1] + mass[i]);
      dummy2->GetXaxis()->SetTitle("#theta (mrad)");
      dummy2->GetYaxis()->SetTitle("rate (arb. units)");
      //dummy2->GetXaxis()->SetRangeUser(0., 0.004);
      //dummy2->GetYaxis()->SetRangeUser(0., 4500000000);
      //dummy2->SetBinContent(1, 0);
      if( j == 0 ) {
	dummy2->Draw();
	dummy2->SetLineColor(1);
      } else if ( j == 1 ) {
	dummy2->SetLineColor(2);
	dummy2->Draw("SAME");
	can2->cd( 12 );
	dummy2->Draw("SAME");
      } else if ( j == 2 ) {
	dummy2->SetLineColor(3);
	dummy2->Draw("SAME");
	can2->cd( 13 );
	dummy2->Draw("SAME");
      } else if ( j == 3 ) {
	dummy2->SetLineColor(4);
	dummy2->Draw("SAME");
	can2->cd( 14 );
	dummy2->Draw("SAME");
      }
      
      can3->cd( i + 1 );
      TH1F* dummy3 = (TH1F*)infile->Get(Form("E_hist%d%d", i, j))->Clone();
      dummy3->SetTitle(histname[2] + mass[i]);
      dummy3->GetXaxis()->SetTitle("E (GeV)");
      dummy3->GetYaxis()->SetTitle("rate (arb. units)");
      //dummy3->GetXaxis()->SetRangeUser(0., 0.004);
      //dummy3->GetYaxis()->SetRangeUser(0., 4500000000);
      //dummy3->SetBinContent(1, 0);
      if( j == 0 ) {
	dummy3->Draw();
	dummy3->SetLineColor(1);
      } else if ( j == 1 ) {
	dummy3->SetLineColor(2);
	dummy3->Draw("SAME");
	can3->cd( 12 );
	dummy3->Draw("SAME");
      } else if ( j == 2 ) {
	dummy3->SetLineColor(3);
	dummy3->Draw("SAME");
	can3->cd( 13 );
	dummy3->Draw("SAME");
      } else if ( j == 3 ) {
	dummy3->SetLineColor(4);
	dummy3->Draw("SAME");
	can3->cd( 14 );
	dummy3->Draw("SAME");
      }

      can4->cd( i + 1 );
      TH1F* dummy4 = (TH1F*)infile->Get(Form("a_hist%d%d", i, j))->Clone();
      dummy4->SetTitle(histname[3] + mass[i]);
      dummy4->GetXaxis()->SetRangeUser(0.9, 1.15);
      dummy4->GetYaxis()->SetRangeUser(25., 35.);
      dummy4->GetYaxis()->SetRangeUser(25., 40.);
      dummy4->GetXaxis()->SetTitle("r (cm)");
      dummy4->GetYaxis()->SetTitle("A_{PV}");
      //dummy4->SetBinContent(1, 0);
      if( j == 0 ) {
	dummy4->Draw();
	dummy4->SetLineColor(1);
      } else if ( j == 1 ) {
	dummy4->SetLineColor(2);
	dummy4->Draw("SAME");
	can4->cd( 12 );
	dummy4->Draw("SAME");
      } else if ( j == 2 ) {
	dummy4->SetLineColor(3);
	dummy4->Draw("SAME");
	can4->cd( 13 );
	dummy4->Draw("SAME");
      } else if ( j == 3 ) {
	dummy4->SetLineColor(4);
	dummy4->Draw("SAME");
	can4->cd( 14 );
	dummy4->Draw("SAME");
      }

      f[i][j] = new TF1(Form("f_%d_%d", i, j), "[0]", 0.9, 1.15);

      can5->cd( i + 1 );
      TH1F* dummy5 = (TH1F*)infile->Get(Form("a_hist%d%d", i, j))->Clone();
      dummy5->SetTitle(histname[3] + mass[i]);
      dummy5->GetXaxis()->SetTitle("r (cm)");
      dummy5->GetYaxis()->SetTitle("A_{PV}");
      dummy5->Rebin(5);
      if( i == 0 ){
	anorm[j] = (TH1F*)dummy5->Clone();
	dummy5->Divide(anorm[j]);
	dummy5->GetXaxis()->SetRangeUser(0.9, 1.15);
	dummy5->GetYaxis()->SetRangeUser(0.9, 1.15);
	dummy5->GetYaxis()->SetRangeUser(0.9, 1.5);
      }else{
	dummy5->Divide(anorm[j]);
	dummy5->GetXaxis()->SetRangeUser(0.9, 1.15);
	dummy5->GetYaxis()->SetRangeUser(0.9, 1.15);
	dummy5->GetYaxis()->SetRangeUser(0.9, 1.5);
      }
      //dummy5->SetBinContent(1, 0);
      if( j == 0 ) {
	dummy5->Draw();
	dummy5->SetLineColor(1);
	dummy5->Fit(Form("f_%d_%d", i, j), "Q", "", 0.96, 1.04);
	//intconstants[j][i] = dummy5->Integral(minbin[j], maxbin[j]);
	intconstants[j][i] = dummy5->Integral(0, 1000);
	cout << intconstants[j][i] << endl;
      } else if ( j == 1 ) {
	dummy5->SetLineColor(2);
	dummy5->Draw("SAME");
	dummy5->Fit(Form("f_%d_%d", i, j), "Q", "", 0.96, 1.04);
	//intconstants[j][i] = dummy5->Integral(minbin[j], maxbin[j]);
	intconstants[j][i] = dummy5->Integral(0, 1000);
	can5->cd( 12 );
	dummy5->Draw("SAME");
      } else if ( j == 2 ) {
	dummy5->SetLineColor(3);
	dummy5->Draw("SAME");
	dummy5->Fit(Form("f_%d_%d", i, j), "Q", "", 0.96, 1.04);
	//intconstants[j][i] = dummy5->Integral(minbin[j], maxbin[j]);
	intconstants[j][i] = dummy5->Integral(0, 1000);
	can5->cd( 13 );
	dummy5->Draw("SAME");
      } else if ( j == 3 ) {
	dummy5->SetLineColor(4);
	dummy5->Draw("SAME");
	dummy5->Fit(Form("f_%d_%d", i, j), "Q", "", 0.96, 1.04);
	//intconstants[j][i] = dummy5->Integral(minbin[j], maxbin[j]);
	intconstants[j][i] = dummy5->Integral(0, 1000);
	can5->cd( 14 );
	dummy5->Draw("SAME");
      }
      
      
    }
  }
  
  TGraph *gr[4];
  can6->cd();
  for(Int_t j = 1; j < 4; j++){
    for(Int_t i = 0; i < 11; i++){
      fitconstants[j][i] = (Float_t)f[i][j]->GetParameter(0);
      if( i > 0 ){
	intconstants[j][i] /= intconstants[j][0];
      }
    }
    
    gr[j] = new TGraph(11, masses, fitconstants[j]);
    //gr[j] = new TGraph(11, masses, intconstants[j]);
    gr[j]->SetMarkerStyle(20);
    gr[j]->SetMarkerColor(j + 1);
    gr[j]->SetLineColor(j + 1);
    gr[j]->SetMarkerSize(1.);
    gr[j]->GetXaxis()->SetTitle("m_{z} (MeV)");
    gr[j]->GetYaxis()->SetTitle("A_z / A_no_z");
    gr[j]->SetTitle("Ratio of assymetries A_z / A_no_z");
    if( j == 1 ){
      gr[j]->Draw("AP");
    }else{
      gr[j]->Draw("P");
    }
  }
  


  can1->SaveAs("Q2.png");
  can2->SaveAs("th.png");
  can3->SaveAs("E.png");
  can4->SaveAs("a.png");
  can5->SaveAs("ra.png");
  can6->SaveAs("ragraph.png");

}

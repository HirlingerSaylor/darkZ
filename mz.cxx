#define mz_cxx
// The class definition in mz.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("mz.C")
// Root > T->Process("mz.C","some options")
// Root > T->Process("mz.C+")
//
#include <TH1F.h>
#include <TH2F.h>
#include "mz.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <math.h>
#include <TMath.h>
using namespace std;

void mz::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

  outfile = new TFile("outfile.root", "RECREATE");
  which_file = 0;
  wi         = 0;

   TString option = GetOption();

   for(Int_t i = 0; i < 64; i++){
     for(Int_t j = 0; j < 4; j++){
       r_hist[i][j]  = new TH1F(Form("r_hist%d%d" , i, j), Form("r_hist%d%d" , i, j), 1000, 0.6,  1.5  );
       a_hist[i][j]  = new TH1F(Form("a_hist%d%d" , i, j), Form("a_hist%d%d" , i, j), 1000, 0.6,  1.5  );
       Q2_hist[i][j] = new TH1F(Form("Q2_hist%d%d", i, j), Form("Q2_hist%d%d", i, j), 1000, 0.0,  0.015);
       th_hist[i][j] = new TH1F(Form("th_hist%d%d", i, j), Form("th_hist%d%d", i, j),  250, 0.0, 25.0  );
       E_hist [i][j] = new TH1F(Form( "E_hist%d%d", i, j), Form( "E_hist%d%d", i, j),  250, 0.0, 11.0  );
       xy_hist[i][j] = new TH2F(Form("xy_hist%d%d", i, j), Form("xy_hist%d%d", i, j), 1000, -2.0, 2.0, 1000, -2.0, 2.0 );

       r_Q2_hist[i][j]  = new TH1F(Form("r_Q2_hist%d%d" , i, j), Form("r_Q2_hist%d%d" , i, j), 1000, 0.0,  0.015  );
       r_th_hist[i][j]  = new TH1F(Form("r_th_hist%d%d" , i, j), Form("r_th_hist%d%d" , i, j), 1000, 0.0,  25  );
       r_EE_hist[i][j]  = new TH1F(Form("r_EE_hist%d%d" , i, j), Form("r_EE_hist%d%d" , i, j), 1000, 0.0,  11  );
       a_Q2_hist[i][j]  = new TH1F(Form("a_Q2_hist%d%d" , i, j), Form("a_Q2_hist%d%d" , i, j), 1000, 0.0,  0.015  );
       a_th_hist[i][j]  = new TH1F(Form("a_th_hist%d%d" , i, j), Form("a_th_hist%d%d" , i, j), 1000, 0.0,  25  );
       a_EE_hist[i][j]  = new TH1F(Form("a_EE_hist%d%d" , i, j), Form("a_EE_hist%d%d" , i, j), 1000, 0.0,  11  );

     }
   }

}

void mz::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t mz::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either mz::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
  fChain->GetTree()->GetEntry(entry);
  
  if( entry == 1 ){
    which_file++;
    wi = which_file - 1;
    cout << "Processing file " << which_file << endl;
  }
  
  Float_t rmin[4] = { 0.935, 0.935, 0.96 , 0.96};
  Float_t rmax[4] = { 1.1  , 1.04 , 1.075, 1.1 };
  Float_t tmin[4] = {                  0.,                  0., 360. / 7. / 8. * 1., 360. / 7. / 8. * 3. };
  Float_t tmax[4] = { 360. / 7. / 8. * 4., 360. / 7. / 8. * 1., 360. / 7. / 8. * 3., 360. / 7. / 8. * 4. };
  
  //cout << entry << endl;
  //Int_t ind_28  = -1;
  //Int_t ind_200 = -1;
  //Int_t ind_201 = -1;
  for( Int_t in = 0; in < 2; in++ ) {
    Float_t m_p   = 0.938;
    Float_t E     = 11.0;
    Float_t E_    = ev_p[in];
    Float_t theta = ev_th[in];
    //cout << E << " " << E_ << " " << theta << endl;
    Float_t mrad  = theta * 1000.;
    Float_t Q2    = 4 * E * E * TMath::Sin( theta / 2 ) * TMath::Sin( theta / 2 ) / ( 1 + 2 * E * TMath::Sin( theta / 2 ) * TMath::Sin( theta / 2 ) / m_p );
    
    for(Int_t i = 0; i < hit_n; i++){
      Float_t theta_red;
      theta_red = TMath::Abs( fmod( abs( hit_ph[i] ), ( 360 / 7 ) ) - ( 360. / 7. / 2. ) );
      if( hit_pid[i] == 11 && ( hit_trid[i] == 1 || hit_trid[i] == 2 ) && hit_det[i] == 28 && hit_r[i] > 0.6 && E > 1.){
	//cout << in << ": " << ev_ph[in] * TMath::RadToDeg() << " " << i << ": " << hit_ph[i] << endl;
	Float_t diff = TMath::Abs( ev_ph[in] * TMath::RadToDeg() - hit_ph[i] );
	if ( diff < 45. || diff > 315. ) { 
	  //cout << in << ": " << ev_ph[in] * TMath::RadToDeg() << " " << i << ": " << hit_ph[i] << endl;
	  /*	if( theta_red < 360. / 7. / 8. ) {
		r_hist [wi][0]->Fill(hit_r[i], ev_Am);
		r_hist [wi][1]->Fill(hit_r[i]);
		r_hist [wi][2]->Fill(hit_r[i], ev_Am);
		//cout << Q2 << endl;
		}*/
	  for(Int_t j = 0; j < 4; j++){
	    if( hit_r[i] > rmin[j] && hit_r[i] < rmax[j] && theta_red > tmin[j] && theta_red < tmax[j] ) {
	      a_hist [wi][j]->Fill(hit_r[i], ev_Am);
	      r_hist [wi][j]->Fill(hit_r[i]);
	      Q2_hist[wi][j]->Fill(Q2   , rate);
	      th_hist[wi][j]->Fill(mrad , rate);
	      E_hist[wi][j]->Fill(E    , rate);
	      xy_hist[wi][j]->Fill(hit_x[i], hit_y[i]);

	      a_Q2_hist [wi][j]->Fill(Q2, ev_Am);
	      a_th_hist [wi][j]->Fill(theta, ev_Am);
	      a_EE_hist [wi][j]->Fill(E, ev_Am);
	      r_Q2_hist [wi][j]->Fill(Q2);
	      r_th_hist [wi][j]->Fill(theta);
	      r_EE_hist [wi][j]->Fill(E);
	    }
	  }
	}
      }
    }
  }
   return kTRUE;
}

void mz::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void mz::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  cout << "Processing asymmetries." << endl;
  for( Int_t i = 0; i < which_file; i++ ){
    for(Int_t j =  0; j < 4; j++){
      a_hist[i][j]->Divide(r_hist[i][j]);
    }
  }
  outfile->Write();

}

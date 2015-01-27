//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 12 16:44:13 2014 by ROOT version 5.34/11
// from TTree T/Geant4 Moller Simulation
// found on file: mz.root
//////////////////////////////////////////////////////////

#ifndef mz_h
#define mz_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1F.h>
#include <TH2F.h>
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class mz : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   TFile* outfile;
   TH1F* r_hist[64][4];
   TH1F* a_hist[64][4];
   TH1F* Q2_hist[64][4];
   TH1F* th_hist[64][4];
   TH1F*  E_hist[64][4];
   TH2F* xy_hist[64][4];

   TH1F* r_Q2_hist[64][4];
   TH1F* r_th_hist[64][4];
   TH1F* r_EE_hist[64][4];
   TH1F* a_Q2_hist[64][4];
   TH1F* a_th_hist[64][4];
   TH1F* a_EE_hist[64][4];

   Int_t which_file;
   Int_t wi;

   // Declaration of leaf types
   Double_t        rate;
   Double_t        ev_A;
   Double_t        ev_Am;
   Double_t        ev_xs;
   Double_t        ev_Q2;
   Double_t        ev_W2;
   Double_t        ev_thcom;
   Double_t        ev_beamp;
   Int_t           ev_npart;
   Int_t           ev_pid[2];   //[ev.npart]
   Double_t        ev_vx[2];   //[ev.npart]
   Double_t        ev_vy[2];   //[ev.npart]
   Double_t        ev_vz[2];   //[ev.npart]
   Double_t        ev_p[2];   //[ev.npart]
   Double_t        ev_px[2];   //[ev.npart]
   Double_t        ev_py[2];   //[ev.npart]
   Double_t        ev_pz[2];   //[ev.npart]
   Double_t        ev_th[2];   //[ev.npart]
   Double_t        ev_ph[2];   //[ev.npart]
   Double_t        ev_tpx[2];   //[ev.npart]
   Double_t        ev_tpy[2];   //[ev.npart]
   Double_t        ev_tpz[2];   //[ev.npart]
   Double_t        bm_x;
   Double_t        bm_y;
   Double_t        bm_z;
   Double_t        bm_dx;
   Double_t        bm_dy;
   Double_t        bm_dz;
   Int_t           hit_n;
   Int_t           hit_det[45];   //[hit.n]
   Int_t           hit_vid[45];   //[hit.n]
   Int_t           hit_pid[45];   //[hit.n]
   Int_t           hit_trid[45];   //[hit.n]
   Int_t           hit_mtrid[45];   //[hit.n]
   Int_t           hit_gen[45];   //[hit.n]
   Double_t        hit_x[45];   //[hit.n]
   Double_t        hit_y[45];   //[hit.n]
   Double_t        hit_z[45];   //[hit.n]
   Double_t        hit_r[45];   //[hit.n]
   Double_t        hit_ph[45];   //[hit.n]
   Double_t        hit_px[45];   //[hit.n]
   Double_t        hit_py[45];   //[hit.n]
   Double_t        hit_pz[45];   //[hit.n]
   Double_t        hit_vx[45];   //[hit.n]
   Double_t        hit_vy[45];   //[hit.n]
   Double_t        hit_vz[45];   //[hit.n]
   Double_t        hit_p[45];   //[hit.n]
   Double_t        hit_e[45];   //[hit.n]
   Double_t        hit_m[45];   //[hit.n]
   Int_t           hit_colCut;
   Int_t           sum_n;
   Int_t           sum_det[40];   //[sum.n]
   Int_t           sum_vid[40];   //[sum.n]
   Double_t        sum_edep[40];   //[sum.n]
   Int_t           sum_pid[40];   //[sum.n]
   Double_t        sum_x[40];   //[sum.n]
   Double_t        sum_y[40];   //[sum.n]
   Double_t        sum_z[40];   //[sum.n]

   // List of branches
   TBranch        *b_rate;   //!
   TBranch        *b_ev_A;   //!
   TBranch        *b_ev_Am;   //!
   TBranch        *b_ev_xs;   //!
   TBranch        *b_ev_Q2;   //!
   TBranch        *b_ev_W2;   //!
   TBranch        *b_ev_thcom;   //!
   TBranch        *b_ev_beamp;   //!
   TBranch        *b_ev_npart;   //!
   TBranch        *b_ev_pid;   //!
   TBranch        *b_ev_vx;   //!
   TBranch        *b_ev_vy;   //!
   TBranch        *b_ev_vz;   //!
   TBranch        *b_ev_p;   //!
   TBranch        *b_ev_px;   //!
   TBranch        *b_ev_py;   //!
   TBranch        *b_ev_pz;   //!
   TBranch        *b_ev_th;   //!
   TBranch        *b_ev_ph;   //!
   TBranch        *b_ev_tpx;   //!
   TBranch        *b_ev_tpy;   //!
   TBranch        *b_ev_tpz;   //!
   TBranch        *b_bm_x;   //!
   TBranch        *b_bm_y;   //!
   TBranch        *b_bm_z;   //!
   TBranch        *b_bm_dx;   //!
   TBranch        *b_bm_dy;   //!
   TBranch        *b_bm_dz;   //!
   TBranch        *b_hit_n;   //!
   TBranch        *b_hit_det;   //!
   TBranch        *b_hit_vid;   //!
   TBranch        *b_hit_pid;   //!
   TBranch        *b_hit_trid;   //!
   TBranch        *b_hit_mtrid;   //!
   TBranch        *b_hit_gen;   //!
   TBranch        *b_hit_x;   //!
   TBranch        *b_hit_y;   //!
   TBranch        *b_hit_z;   //!
   TBranch        *b_hit_r;   //!
   TBranch        *b_hit_ph;   //!
   TBranch        *b_hit_px;   //!
   TBranch        *b_hit_py;   //!
   TBranch        *b_hit_pz;   //!
   TBranch        *b_hit_vx;   //!
   TBranch        *b_hit_vy;   //!
   TBranch        *b_hit_vz;   //!
   TBranch        *b_hit_p;   //!
   TBranch        *b_hit_e;   //!
   TBranch        *b_hit_m;   //!
   TBranch        *b_hit_colCut;   //!
   TBranch        *b_sum_n;   //!
   TBranch        *b_sum_det;   //!
   TBranch        *b_sum_vid;   //!
   TBranch        *b_sum_edep;   //!
   TBranch        *b_sum_pid;   //!
   TBranch        *b_sum_x;   //!
   TBranch        *b_sum_y;   //!
   TBranch        *b_sum_z;   //!

   mz(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~mz() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(mz,0);
};

#endif

#ifdef mz_cxx
void mz::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("rate", &rate, &b_rate);
   fChain->SetBranchAddress("ev.A", &ev_A, &b_ev_A);
   fChain->SetBranchAddress("ev.Am", &ev_Am, &b_ev_Am);
   fChain->SetBranchAddress("ev.xs", &ev_xs, &b_ev_xs);
   fChain->SetBranchAddress("ev.Q2", &ev_Q2, &b_ev_Q2);
   fChain->SetBranchAddress("ev.W2", &ev_W2, &b_ev_W2);
   fChain->SetBranchAddress("ev.thcom", &ev_thcom, &b_ev_thcom);
   fChain->SetBranchAddress("ev.beamp", &ev_beamp, &b_ev_beamp);
   fChain->SetBranchAddress("ev.npart", &ev_npart, &b_ev_npart);
   fChain->SetBranchAddress("ev.pid", ev_pid, &b_ev_pid);
   fChain->SetBranchAddress("ev.vx", ev_vx, &b_ev_vx);
   fChain->SetBranchAddress("ev.vy", ev_vy, &b_ev_vy);
   fChain->SetBranchAddress("ev.vz", ev_vz, &b_ev_vz);
   fChain->SetBranchAddress("ev.p", ev_p, &b_ev_p);
   fChain->SetBranchAddress("ev.px", ev_px, &b_ev_px);
   fChain->SetBranchAddress("ev.py", ev_py, &b_ev_py);
   fChain->SetBranchAddress("ev.pz", ev_pz, &b_ev_pz);
   fChain->SetBranchAddress("ev.th", ev_th, &b_ev_th);
   fChain->SetBranchAddress("ev.ph", ev_ph, &b_ev_ph);
   fChain->SetBranchAddress("ev.tpx", ev_tpx, &b_ev_tpx);
   fChain->SetBranchAddress("ev.tpy", ev_tpy, &b_ev_tpy);
   fChain->SetBranchAddress("ev.tpz", ev_tpz, &b_ev_tpz);
   fChain->SetBranchAddress("bm.x", &bm_x, &b_bm_x);
   fChain->SetBranchAddress("bm.y", &bm_y, &b_bm_y);
   fChain->SetBranchAddress("bm.z", &bm_z, &b_bm_z);
   fChain->SetBranchAddress("bm.dx", &bm_dx, &b_bm_dx);
   fChain->SetBranchAddress("bm.dy", &bm_dy, &b_bm_dy);
   fChain->SetBranchAddress("bm.dz", &bm_dz, &b_bm_dz);
   fChain->SetBranchAddress("hit.n", &hit_n, &b_hit_n);
   fChain->SetBranchAddress("hit.det", hit_det, &b_hit_det);
   fChain->SetBranchAddress("hit.vid", hit_vid, &b_hit_vid);
   fChain->SetBranchAddress("hit.pid", hit_pid, &b_hit_pid);
   fChain->SetBranchAddress("hit.trid", hit_trid, &b_hit_trid);
   fChain->SetBranchAddress("hit.mtrid", hit_mtrid, &b_hit_mtrid);
   fChain->SetBranchAddress("hit.gen", hit_gen, &b_hit_gen);
   fChain->SetBranchAddress("hit.x", hit_x, &b_hit_x);
   fChain->SetBranchAddress("hit.y", hit_y, &b_hit_y);
   fChain->SetBranchAddress("hit.z", hit_z, &b_hit_z);
   fChain->SetBranchAddress("hit.r", hit_r, &b_hit_r);
   fChain->SetBranchAddress("hit.ph", hit_ph, &b_hit_ph);
   fChain->SetBranchAddress("hit.px", hit_px, &b_hit_px);
   fChain->SetBranchAddress("hit.py", hit_py, &b_hit_py);
   fChain->SetBranchAddress("hit.pz", hit_pz, &b_hit_pz);
   fChain->SetBranchAddress("hit.vx", hit_vx, &b_hit_vx);
   fChain->SetBranchAddress("hit.vy", hit_vy, &b_hit_vy);
   fChain->SetBranchAddress("hit.vz", hit_vz, &b_hit_vz);
   fChain->SetBranchAddress("hit.p", hit_p, &b_hit_p);
   fChain->SetBranchAddress("hit.e", hit_e, &b_hit_e);
   fChain->SetBranchAddress("hit.m", hit_m, &b_hit_m);
   fChain->SetBranchAddress("hit.colCut", &hit_colCut, &b_hit_colCut);
   fChain->SetBranchAddress("sum.n", &sum_n, &b_sum_n);
   fChain->SetBranchAddress("sum.det", sum_det, &b_sum_det);
   fChain->SetBranchAddress("sum.vid", sum_vid, &b_sum_vid);
   fChain->SetBranchAddress("sum.edep", sum_edep, &b_sum_edep);
   fChain->SetBranchAddress("sum.pid", sum_pid, &b_sum_pid);
   fChain->SetBranchAddress("sum.x", sum_x, &b_sum_x);
   fChain->SetBranchAddress("sum.y", sum_y, &b_sum_y);
   fChain->SetBranchAddress("sum.z", sum_z, &b_sum_z);
}

Bool_t mz::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef mz_cxx

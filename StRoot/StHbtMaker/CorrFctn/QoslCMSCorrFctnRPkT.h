#ifndef QoslCMSCorrFctnRPkT_hh
#define QoslCMSCorrFctnRPkT_hh

#include "StHbtMaker/Base/StHbtCorrFctn.hh"
#include "StHbtMaker/Base/StHbtPairCut.h"
#include "StHbtMaker/Infrastructure/StHbtCoulomb.h"

class TH3F;

class QoslCMSCorrFctnRPkT : public StHbtCorrFctn {
public:
  QoslCMSCorrFctnRPkT(char* title, const int& nbinso, const float& QoLo, const float& QoHi,
	       const int& nbinss, const float& QsLo, const float& QsHi,
	       const int& nbinsl, const float& QlLo, const float& QlHi, const int& rpBins);
  virtual ~QoslCMSCorrFctnRPkT();

  virtual StHbtString Report();
  virtual void AddRealPair(const StHbtPair*);
  virtual void AddMixedPair(const StHbtPair*);
  void SetCorrection(StHbtCoulomb*);
  void SetSpecificPairCut(StHbtPairCut*);
  void SetChargeRadius(const Double_t);

  virtual void Finish();

  float qMax;
	
	int nRPbins;
  int nKtBins;
  
  TH3F* Numerator3D(const int& rpBin, const int& ktBin);
  TH3F* Denominator3D(const int& rpBin, const int& ktBin);
  StHbt3DHisto* QinvHisto3D(const int& rpBin, const int& ktBin);
  StHbt3DHisto* CoulHisto3D(const int& rpBin, const int& ktBin);

private:
  TH3F* mNumerator[12][5];
  TH3F* mDenominator[12][5];
  StHbt3DHisto* mQinvHisto[12][5];
  StHbt3DHisto* mCoulHisto[12][5];

  StHbtCoulomb* mCorrection; //!
  StHbtPairCut* mPairCut;    //! this is a PairCut specific to THIS CorrFctn

  int GetRPBin(const StHbtPair*);
  int GetKtBin(const StHbtPair*);
  Double_t mChargeRadius;
  
  
#ifdef __ROOT__ 
  ClassDef(QoslCMSCorrFctnRPkT, 1)
#endif
};

inline  TH3F* QoslCMSCorrFctnRPkT::Numerator3D(const int& rpBin, const int& ktBin){return mNumerator[rpBin][ktBin];}
inline  TH3F* QoslCMSCorrFctnRPkT::Denominator3D(const int& rpBin, const int& ktBin){return mDenominator[rpBin][ktBin];}
inline  StHbt3DHisto* QoslCMSCorrFctnRPkT::QinvHisto3D(const int& rpBin, const int& ktBin){return mQinvHisto[rpBin][ktBin];}
inline  StHbt3DHisto* QoslCMSCorrFctnRPkT::CoulHisto3D(const int& rpBin, const int& ktBin){return mCoulHisto[rpBin][ktBin];}
inline  void QoslCMSCorrFctnRPkT::SetSpecificPairCut(StHbtPairCut* pc){mPairCut=pc;}

#endif


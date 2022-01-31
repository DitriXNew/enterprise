#ifndef _CONSTANTS_MANAGER_H__
#define _CONSTANTS_MANAGER_H__

#include "constant.h"

class CManagerConstantValue : public CValue {
	wxDECLARE_DYNAMIC_CLASS(CManagerConstantValue);
protected:
	CMetaConstantObject *m_metaConst;
public:

	CManagerConstantValue(CMetaConstantObject *metaConst = NULL);
	virtual ~CManagerConstantValue();

	virtual CMethods* GetPMethods() const { PrepareNames();  return &m_methods; }; //�������� ������ �� ����� �������� ������� ���� ��������� � �������
	virtual void PrepareNames() const;                         //���� ����� ������������� ���������� ��� ������������� ���� ��������� � �������
	virtual CValue Method(methodArg_t &aParams);//����� ������

	//Get ref class 
	virtual CLASS_ID GetTypeID() const;

	//types 
	virtual wxString GetTypeString() const;
	virtual wxString GetString() const;

protected:

	//methos 
	static CMethods m_methods;
};


#endif // !_CONSTANTS_MANAGER_H__

#ifndef _MANAGER_CATALOG_H__
#define _MANAGER_CATALOG_H__

#include "catalog.h"
#include "common/managerInfo.h"

class CManagerCatalogValue : public CValue,
	public IMetaManagerInfo {
	wxDECLARE_DYNAMIC_CLASS(CManagerCatalogValue);
public:

	CManagerCatalogValue(CMetaObjectCatalogValue *metaObject = NULL);
	virtual ~CManagerCatalogValue();

	virtual CMetaCommonModuleObject *GetModuleManager() const;

	CValue FindByCode(const CValue &vCode);
	CValue FindByName(const CValue &vName);

	CValue EmptyRef();

	virtual CMethods* GetPMethods() const { PrepareNames();  return m_methods; }; //�������� ������ �� ����� �������� ������� ���� ��������� � �������
	virtual void PrepareNames() const;                         //���� ����� ������������� ���������� ��� ������������� ���� ��������� � �������
	virtual CValue Method(methodArg_t &aParams);//����� ������

	//Get ref class 
	virtual CLASS_ID GetTypeID() const;

	//types 
	virtual wxString GetTypeString() const;
	virtual wxString GetString() const;

protected:
	//methos 
	CMethods *m_methods;
	CMetaObjectCatalogValue *m_metaObject;
};

#endif 
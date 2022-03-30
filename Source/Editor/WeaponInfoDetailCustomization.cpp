#include "WeaponInfoDetailCustomization.h"
#include "GunSystem/WeaponInfo.h"
#include "PropertyEditing.h"

#define LOCTEXT_NAMESPACE "FEditorModule"

TSharedRef< IDetailCustomization > FWeaponInfoDetailCustomization::MakeInstance()
{
	return MakeShareable(new FWeaponInfoDetailCustomization);
}

void FWeaponInfoDetailCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TSharedRef< IPropertyHandle > Prop = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UWeaponInfo, AttackType));

	
}

#undef LOCTEXT_NAMESPACE
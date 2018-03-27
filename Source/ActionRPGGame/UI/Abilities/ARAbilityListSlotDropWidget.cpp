// Fill out your copyright notice in the Description page of Project Settings.

#include "ARAbilityListSlotDropWidget.h"

#include "ARAbilityListSlotDragWidget.h"
#include "Abilities/ARAbilityManagerComponent.h"
#include "UI/ARUIComponent.h"

bool UARAbilityListSlotDropWidget::NativeOnDrop(const FGeometry& InGeometry
	, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	UARAbilityListSlotDragWidget* Payload = Cast<UARAbilityListSlotDragWidget>(InOperation->Payload);
	FSlateBrush brush = Payload->IconImage->Brush;
	
	AbilityManager->NativeEquipAbility(Payload->GetAbilityTag(), AbilityGroup, AbilitySlot);

	IconImage->SetBrush(brush);
	if (AbilitySlot == EAMSlot::Slot001)
	{
		UIComponent->HUDWidget->PlayerInfo->AbilityGroup001Slot001->AbilityIcon->SetBrush(brush); //DAT BAD
	}
	return true;
}
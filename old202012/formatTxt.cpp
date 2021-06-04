std::shared_ptr<CEAPCIMetaLookup> lookupTask = nullptr;
		HRESULT hr = METASERVICE->
			QueryLookup(CEAPCIMetaTableQueryParameter(L"PMTaskState"),
				lookupTask);
		EAP_ERROR_RETURN(hr, L"METASERVICE->QueryLookup");

		std::wstring sUnRelease = L"";

		for (auto& item : lookupTask->items)
		{
			if (item->GetIndex() == ENUM_TASK_STATE_NO_RELEASE)
			{
				sUnRelease = item->GetValue();
				break;
			}
		}

		std::wstring pStateStr = pEntity->GetStringValue(L"state");

		if (pStateStr.compare(sUnRelease) != 0)
		{
			return S_OK;
		}
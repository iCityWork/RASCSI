//---------------------------------------------------------------------------
//
// SCSI Target Emulator RaSCSI (*^..^*)
// for Raspberry Pi
//
// Copyright (C) 2021 Uwe Seimet
//
// A BlockDevice supports SCSI block commands (see https://www.t10.org/drafts.htm, SBC-5)
//
//---------------------------------------------------------------------------

#pragma once

#include "primary_device.h"

class SASIDEV;

class BlockDevice : public PrimaryDevice
{
public:

	BlockDevice(const string& id) : PrimaryDevice(id) {};
	virtual ~BlockDevice() {};

	// Mandatory commands
	virtual void TestUnitReady(SASIDEV *) override = 0;
	virtual void Inquiry(SASIDEV *) override = 0;
	virtual void ReportLuns(SASIDEV *) override = 0;
	virtual void Format(SASIDEV *) = 0;
	virtual void ReadCapacity10(SASIDEV *) = 0;
	virtual void ReadCapacity16(SASIDEV *) = 0;
	virtual void Read10(SASIDEV *) = 0;
	virtual void Read16(SASIDEV *) = 0;
	virtual void Write10(SASIDEV *) = 0;
	virtual void Write16(SASIDEV *) = 0;

	virtual void RequestSense(SASIDEV *) override = 0;
	virtual void ModeSense(SASIDEV *) override = 0;
	virtual void ModeSense10(SASIDEV *) override = 0;
	virtual void ModeSelect(SASIDEV *) override = 0;

	// TODO Add the other optional commands currently implemented
};

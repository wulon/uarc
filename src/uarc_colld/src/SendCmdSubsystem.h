/*
 * SendCmdSubsystem.h
 *
 *  Created on: 2014-10-10
 *      Author: root
 */

#ifndef SENDCMDSUBSYSTEM_H_
#define SENDCMDSUBSYSTEM_H_

#include "uarc_colld.h"
#include "rdbms.h"
#include "CommStruct.h"
#include "VIEC104/VIEC104Subsystem.h"
#include "IEC104/IEC104Subsystem.h"
#include <Poco/Util/Subsystem.h>
#include <Poco/Runnable.h>
#include <Poco/Thread.h>

using Uarc::Protocol::VIEC104::VIEC104Subsystem;
using Uarc::Protocol::IEC104::IEC104Subsystem;

class SendCmdSubsystem  : public Poco::Util::Subsystem, public Poco::Runnable {

public:

	SendCmdSubsystem();
	const char* name() const;
	virtual ~SendCmdSubsystem();

	void initialize(Poco::Util::Application& self);
	void uninitialize();
	void Start();
	void run();
	void Stop();

private:

	bool 			_stopped;
	Poco::Thread 	_thread;
	CRtDbMs*        _rtdbms;

};

bool DataZhaoceTaskRun(const ZhaoCeExecInfoData& zhaoceInfo);

bool ControlCmdTaskRun(const ControlExecInfoData& ctrlTask);

#endif /* SENDCMDSUBSYSTEM_H_ */

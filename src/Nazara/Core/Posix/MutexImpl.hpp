// Copyright (C) 2015 Alexandre Janniaux
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_MUTEXIMPL_HPP
#define NAZARA_MUTEXIMPL_HPP

#include <pthread.h>

namespace Nz
{
	class MutexImpl
	{
		friend class ConditionVariableImpl;

		public:
			MutexImpl();
			~MutexImpl();

			void Lock();
			bool TryLock();
			void Unlock();

		private:
			pthread_mutex_t m_handle;
	};
}

#endif // NAZARA_MUTEXIMPL_HPP

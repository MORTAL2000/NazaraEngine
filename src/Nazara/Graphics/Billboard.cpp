// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Engine - Graphics module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Graphics/Billboard.hpp>
#include <Nazara/Graphics/AbstractRenderQueue.hpp>
#include <Nazara/Graphics/AbstractViewer.hpp>
#include <Nazara/Math/Algorithm.hpp>
#include <cstring>
#include <memory>
#include <Nazara/Graphics/Debug.hpp>

namespace Nz
{
	void Billboard::AddToRenderQueue(AbstractRenderQueue* renderQueue, const InstanceData& instanceData) const
	{
		if (!m_material)
			return;

		renderQueue->AddBillboard(instanceData.renderOrder, m_material, instanceData.transformMatrix.GetTranslation(), m_size, m_sinCos, m_color);
	}

	void Billboard::MakeBoundingVolume() const
	{
		constexpr float sqrt2 = float(M_SQRT2);

		m_boundingVolume.Set(Vector3f(0.f), sqrt2*m_size.x*Vector3f::Right() + sqrt2*m_size.y*Vector3f::Down());
	}

	BillboardLibrary::LibraryMap Billboard::s_library;
}

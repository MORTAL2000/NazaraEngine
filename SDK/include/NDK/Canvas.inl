// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Development Kit"
// For conditions of distribution and use, see copyright notice in Prerequesites.hpp

#include <NDK/Canvas.hpp>

namespace Ndk
{
	inline Canvas::Canvas(WorldHandle world, Nz::EventHandler& eventHandler) :
	m_hoveredWidget(nullptr),
	m_keyboardOwner(nullptr),
	m_world(std::move(world))
	{
		m_canvas = this;

		m_mouseButtonPressedSlot.Connect(eventHandler.OnMouseButtonPressed, this, &Canvas::OnMouseButtonPressed);
		m_mouseButtonReleasedSlot.Connect(eventHandler.OnMouseButtonReleased, this, &Canvas::OnMouseButtonRelease);
		m_mouseMovedSlot.Connect(eventHandler.OnMouseMoved, this, &Canvas::OnMouseMoved);
		m_mouseLeftSlot.Connect(eventHandler.OnMouseLeft, this, &Canvas::OnMouseLeft);
		m_textEnteredSlot.Connect(eventHandler.OnTextEntered, this, &Canvas::OnTextEntered);
	}

	inline const WorldHandle& Canvas::GetWorld() const
	{
		return m_world;
	}

	inline void Ndk::Canvas::SetKeyboardOwner(BaseWidget* widget)
	{
		m_keyboardOwner = widget;
	}
}
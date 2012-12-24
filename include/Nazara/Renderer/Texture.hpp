// Copyright (C) 2012 Jérôme Leclercq
// This file is part of the "Nazara Engine - Renderer module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_TEXTURE_HPP
#define NAZARA_TEXTURE_HPP

#include <Nazara/Prerequesites.hpp>
#include <Nazara/Core/NonCopyable.hpp>
#include <Nazara/Renderer/Enums.hpp>
#include <Nazara/Utility/Image.hpp>
#include <Nazara/Utility/PixelFormat.hpp>

class NzRenderTexture;
struct NzTextureImpl;

class NAZARA_API NzTexture : public NzResource, NzNonCopyable
{
	friend NzRenderTexture;
	friend class NzShader;

	public:
		NzTexture() = default;
		explicit NzTexture(const NzImage& image);
		~NzTexture();

		bool Create(nzImageType type, nzPixelFormat format, unsigned int width, unsigned int height, unsigned int depth = 1, nzUInt8 levelCount = 1, bool lock = false);
		void Destroy();

		bool Download(NzImage* image) const;

		bool EnableMipmapping(bool enable);

		nzUInt8 GetBytesPerPixel() const;
		unsigned int GetDepth() const;
		nzSamplerFilter GetFilterMode() const;
		nzPixelFormat GetFormat() const;
		unsigned int GetHeight() const;
		nzImageType GetType() const;
		unsigned int GetWidth() const;

		bool HasMipmaps() const;

		bool IsCompressed() const;
		bool IsCubemap() const;
		bool IsTarget() const;
		bool IsValid() const;

		bool LoadFromFile(const NzString& filePath, const NzImageParams& params = NzImageParams(), bool generateMipmaps = true);
		bool LoadFromImage(const NzImage& image, bool generateMipmaps = true);
		bool LoadFromMemory(const void* data, std::size_t size, const NzImageParams& params = NzImageParams(), bool generateMipmaps = true);
		bool LoadFromStream(NzInputStream& stream, const NzImageParams& params = NzImageParams(), bool generateMipmaps = true);

		bool Lock();

		bool SetMipmapRange(nzUInt8 minLevel, nzUInt8 maxLevel);

		bool Update(const NzImage& image, nzUInt8 level = 0);
		bool Update(const NzImage& image, const NzRectui& rect, unsigned int z = 0, nzUInt8 level = 0);
		bool Update(const NzImage& image, const NzCubeui& cube, nzUInt8 level = 0);
		bool Update(const nzUInt8* pixels, nzUInt8 level = 0);
		bool Update(const nzUInt8* pixels, const NzRectui& rect, unsigned int z = 0, nzUInt8 level = 0);
		bool Update(const nzUInt8* pixels, const NzCubeui& cube, nzUInt8 level = 0);
		bool UpdateFace(nzCubemapFace face, const NzImage& image, nzUInt8 level = 0);
		bool UpdateFace(nzCubemapFace face, const NzImage& image, const NzRectui& rect, nzUInt8 level = 0);
		bool UpdateFace(nzCubemapFace face, const nzUInt8* pixels, nzUInt8 level = 0);
		bool UpdateFace(nzCubemapFace face, const nzUInt8* pixels, const NzRectui& rect, nzUInt8 level = 0);

		void Unlock();

		// Fonctions OpenGL
		bool Bind() const;
		unsigned int GetOpenGLID() const;

		static unsigned int GetValidSize(unsigned int size);
		static bool IsFormatSupported(nzPixelFormat format);
		static bool IsMipmappingSupported();
		static bool IsTypeSupported(nzImageType type);

	private:
		NzRenderTexture* GetRenderTexture() const;
		void SetRenderTexture(NzRenderTexture* renderTexture);

		NzTextureImpl* m_impl = nullptr;
};

#endif // NAZARA_TEXTURE_HPP

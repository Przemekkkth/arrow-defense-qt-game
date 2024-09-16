#include "pixmapmanager.h"

PixmapManager* PixmapManager::ptr = nullptr;

PixmapManager *PixmapManager::Instance()
{
    if(!ptr)
    {
        ptr = new PixmapManager();
    }
    return ptr;
}

QPixmap& PixmapManager::getPixmap(TextureID id)
{
    return m_textures.get(id);
}

PixmapManager::PixmapManager()
{
    m_textures.load(TextureID::Arrow, QStringLiteral(":/assets/arrow.png"));
    m_textures.load(TextureID::Line, QStringLiteral(":/assets/line.png"));
    m_textures.load(TextureID::Wrong, QStringLiteral(":/assets/wrong.png"));

    //std::unique_ptr<QPixmap> ButtonSelected(new QPixmap(getPixmap(TextureID::Buttons).copy(0,50,200,50)));
    //m_textures.insertResource(TextureID::ButtonSelected, std::move(ButtonSelected));
}

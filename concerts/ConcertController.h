#ifndef CONCERTCONTROLLER_H
#define CONCERTCONTROLLER_H

#include <QMutex>
#include <QObject>
#include "data/Concert.h"
#include "data/ConcertScraperInterface.h"
#include "data/MediaCenterInterface.h"
#include "globals/DownloadManagerElement.h"
#include "globals/DownloadManager.h"

class ConcertScraperInterface;
class DownloadManager;
class MediaCenterInterface;

class ConcertController : public QObject
{
    Q_OBJECT
public:
    explicit ConcertController(Concert *parent = 0);

    bool saveData(MediaCenterInterface *mediaCenterInterface);
    bool loadData(MediaCenterInterface *mediaCenterInterface, bool force = false, bool reloadFromNfo = true);
    void loadData(QString id, ConcertScraperInterface *scraperInterface, QList<int> infos);
    void loadStreamDetailsFromFile();
    void scraperLoadDone(ConcertScraperInterface *scraper);
    QList<int> infosToLoad();
    bool infoLoaded() const;
    bool downloadsInProgress() const;
    void loadImage(int type, QUrl url);
    void loadImages(int type, QList<QUrl> urls);
    void abortDownloads();
    void setLoadsLeft(QList<ScraperData> loadsLeft);
    void removeFromLoadsLeft(ScraperData load);
    void setInfosToLoad(QList<int> infos);

signals:
    void sigInfoLoadDone(Concert*);
    void sigLoadDone(Concert*);
    void sigLoadImagesStarted(Concert*);
    void sigDownloadProgress(Concert*, int, int);
    void sigLoadingImages(Concert*, QList<int>);
    void sigImage(Concert*, int, QByteArray);

private slots:
    void onFanartLoadDone(Concert* concert, QMap<int, QList<Poster> > posters);
    void onAllDownloadsFinished();
    void onDownloadFinished(DownloadManagerElement elem);

private:
    Concert *m_concert;
    bool m_infoLoaded;
    bool m_infoFromNfoLoaded;
    QList<int> m_infosToLoad;
    DownloadManager *m_downloadManager;
    bool m_downloadsInProgress;
    int m_downloadsSize;
    int m_downloadsLeft;
    QList<ScraperData> m_loadsLeft;
    bool m_loadDoneFired;
    QMutex m_loadMutex;
};

#endif // CONCERTCONTROLLER_H

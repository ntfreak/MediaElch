#ifndef MOVIE_H
#define MOVIE_H

#include <QDate>
#include <QDebug>
#include <QPixmap>
#include <QObject>
#include <QStringList>
#include <QUrl>

#include "globals/Globals.h"
#include "data/MediaCenterInterface.h"
#include "data/ScraperInterface.h"
#include "data/StreamDetails.h"
#include "movies/MovieController.h"

class MovieController;
class MediaCenterInterface;
class ScraperInterface;
class StreamDetails;

/**
 * @brief The Movie class
 * This class represents a single movie
 */
class Movie : public QObject
{
    Q_OBJECT

public:
    explicit Movie(QStringList files, QObject *parent = 0);
    ~Movie();

    MovieController *controller();

    void clear();
    void clear(QList<int> infos);

    QString name() const;
    QString sortTitle() const;
    QString originalName() const;
    QString overview() const;
    qreal rating() const;
    int votes() const;
    int top250() const;
    QDate released() const;
    QString tagline() const;
    QString outline() const;
    int runtime() const;
    QString certification() const;
    QString writer() const;
    QString director() const;
    QStringList genres() const;
    QList<QString*> genresPointer();
    QStringList countries() const;
    QList<QString*> countriesPointer();
    QStringList studios() const;
    QStringList tags() const;
    QList<QString*> studiosPointer();
    QUrl trailer() const;
    QList<Actor> actors() const;
    QList<Actor*> actorsPointer();
    QStringList files() const;
    QString folderName() const;
    int playcount() const;
    QDateTime lastPlayed() const;
    QString id() const;
    QString tmdbId() const;
    QString mediaPassionId() const;
    QString set() const;
    bool watched() const;
    int movieId() const;
    bool inSeparateFolder() const;
    int mediaCenterId() const;
    int numPrimaryLangPosters() const;
    StreamDetails *streamDetails();
    bool streamDetailsLoaded() const;
    QDateTime fileLastModified() const;
    QString nfoContent() const;
    int databaseId() const;
    bool syncNeeded() const;
    bool hasLocalTrailer() const;
    QDateTime dateAdded() const;

    bool hasChanged() const;

    void setFiles(QStringList files);
    void setName(QString name);
    void setSortTitle(QString sortTitle);
    void setOriginalName(QString originalName);
    void setOverview(QString overview);
    void setRating(qreal rating);
    void setVotes(int votes);
    void setTop250(int top250);
    void setReleased(QDate released);
    void setTagline(QString tagline);
    void setOutline(QString outline);
    void setRuntime(int runtime);
    void setCertification(QString certification);
    void setWriter(QString writer);
    void setDirector(QString director);
    void addStudio(QString studio);
    void addTag(QString tag);
    void setTrailer(QUrl trailer);
    void setActors(QList<Actor> actors);
    void addActor(Actor actor);
    void addGenre(QString genre);
    void addCountry(QString country);
    void setPlayCount(int playcount);
    void setLastPlayed(QDateTime lastPlayed);
    void setId(QString id);
    void setTmdbId(QString id);
    void setMediaPassionId(QString id);
    void setSet(QString set);
    void setWatched(bool watched);
    void setChanged(bool changed);
    void setDownloadsInProgress(bool inProgress);
    void setDownloadsSize(int downloadsSize);
    void setInSeparateFolder(bool inSepFolder);
    void setMediaCenterId(int mediaCenterId);
    void setNumPrimaryLangPosters(int numberPrimaryLangPosters);
    void setStreamDetailsLoaded(bool loaded);
    void setFileLastModified(QDateTime modified);
    void setNfoContent(QString content);
    void setDatabaseId(int id);
    void setSyncNeeded(bool syncNeeded);
    void setDateAdded(QDateTime date);

    void removeActor(Actor *actor);
    void removeCountry(QString *country);
    void removeCountry(QString country);
    void removeStudio(QString *studio);
    void removeStudio(QString studio);
    void removeGenre(QString *genre);
    void removeGenre(QString genre);
    void removeTag(QString tag);

    QList<Poster> posters() const;
    QList<Poster> backdrops() const;
    QList<Poster> discArts() const;
    QList<Poster> clearArts() const;
    QList<Poster> logos() const;
    QList<ExtraFanart> extraFanarts(MediaCenterInterface *mediaCenterInterface);
    QStringList extraFanartsToRemove();
    QList<QByteArray> extraFanartImagesToAdd();
    QList<int> imagesToRemove() const;

    void addPoster(Poster poster, bool primaryLang = false);
    void addBackdrop(Poster backdrop);
    void addDiscArt(Poster poster);
    void addClearArt(Poster poster);
    void addLogo(Poster poster);
    void addExtraFanart(QByteArray fanart);
    void removeExtraFanart(QByteArray fanart);
    void removeExtraFanart(QString file);
    void clearExtraFanartData();
    void clearImages();
    void removeImage(int type);

    // Images
    bool hasExtraFanarts() const;
    void setHasExtraFanarts(bool has);
    QByteArray image(int imageType);
    bool imageHasChanged(int imageType);
    void setHasImage(int imageType, bool has);
    bool hasImage(int imageType);
    void setImage(int imageType, QByteArray image);

    DiscType discType();
    void setDiscType(DiscType type);

    static bool lessThan(Movie *a, Movie *b);
    static QList<int> imageTypes();

signals:
    void sigChanged(Movie*);

private:
    MovieController *m_controller;
    QStringList m_files;
    QString m_folderName;
    QString m_name;
    QString m_sortTitle;
    QString m_originalName;
    QString m_overview;
    qreal m_rating;
    int m_votes;
    int m_top250;
    QDate m_released;
    QString m_tagline;
    QString m_outline;
    int m_runtime;
    QString m_certification;
    QString m_writer;
    QString m_director;
    QStringList m_genres;
    QStringList m_countries;
    QStringList m_studios;
    QStringList m_tags;
    QUrl m_trailer;
    QList<Actor> m_actors;
    int m_playcount;
    QDateTime m_lastPlayed;
    QString m_id;
    QString m_tmdbId;
    QString m_mediaPassionId;
    QString m_set;
    QList<Poster> m_posters;
    QList<Poster> m_backdrops;
    QList<Poster> m_discArts;
    QList<Poster> m_clearArts;
    QList<Poster> m_logos;
    QStringList m_extraFanartsToRemove;
    QStringList m_extraFanarts;
    bool m_infoLoaded;
    bool m_infoFromNfoLoaded;
    bool m_imagesLoaded;
    bool m_watched;
    bool m_hasChanged;
    int m_movieId;
    bool m_inSeparateFolder;
    int m_mediaCenterId;
    int m_numPrimaryLangPosters;
    bool m_hasExtraFanarts;
    bool m_syncNeeded;
    bool m_streamDetailsLoaded;
    StreamDetails *m_streamDetails;
    QDateTime m_fileLastModified;
    QString m_nfoContent;
    int m_databaseId;
    QDateTime m_dateAdded;
    DiscType m_discType;

    // Images
    QMap<int, QByteArray> m_images;
    QMap<int, bool> m_hasImage;
    QMap<int, bool> m_hasImageChanged;
    QList<QByteArray> m_extraFanartImagesToAdd;
    QList<int> m_imagesToRemove;
};

Q_DECLARE_METATYPE(Movie*)

QDebug operator<<(QDebug dbg, const Movie &movie);
QDebug operator<<(QDebug dbg, const Movie *movie);

#endif // MOVIE_H

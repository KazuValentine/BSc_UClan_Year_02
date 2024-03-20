class Movie {
  bool adult = false;
  String backdropPath = "";
  int id = 0;
  String title = "";
  String originalLanguage = "";
  String originalTitle = "";
  String overview = "";
  String posterPath = "";
  String mediaType = "";
  List<int> genreIds = [];
  double popularity = 0;
  String releaseDate = "";
  bool video = false;
  double voteAverage = 0;
  int voteCount = 0;

  Movie(
      {required this.adult,
      required this.backdropPath,
      required this.id,
      required this.title,
      required this.originalLanguage,
      required this.originalTitle,
      required this.overview,
      required this.posterPath,
      required this.mediaType,
      // required this.genreIds,
      required this.popularity,
      required this.releaseDate,
      required this.video,
      required this.voteAverage,
      required this.voteCount});

  factory Movie.fromJson(Map<String, dynamic> json) {
    return Movie(
        adult: json["adult"] ?? true,
        backdropPath: json["backdrop_path"] ?? "null",
        id: json["id"] ?? -1,
        title: json["title"] ?? "null",
        originalLanguage: json["original_language"] ?? "null",
        originalTitle: json["original_title"] ?? "null",
        overview: json["overview"] ?? "null",
        posterPath: json["poster_path"] ?? "null",
        mediaType: json["media_type"] ?? "null",
        // genreIds: json[""] ?? "null",
        popularity: json["popularity"] ?? -1,
        releaseDate: json["release_date"] ?? "null",
        video: json["video"] ?? false,
        voteAverage: json["vote_average"] ?? -1,
        voteCount: json["vote_count"] ?? -1);
  }

  // Map<String, dynamic> toJson() => {
  //   "adult": adult,
  //   "backdrop_path": backdropPath
  // };
}

// "adult": false,
// "backdrop_path": "/gzlprPDmKCS4bUT4BxQZmJfpMX9.jpg",
// "id": 636706,
// "title": "Spaceman",
// "original_language": "en",
// "original_title": "Spaceman",
// "overview": "During a research mission, an astronaut discovers that his marriage is in trouble. Luckily, he has the help of a mysterious creature hidden in his ship.",
// "poster_path": "/jDdnDEGu3GiLtJwDXeL4hfFzmGv.jpg",
// "media_type": "movie",
// "genre_ids": [
// 878,
// 18
// ] ?? "null",
// "popularity": 108.612,
// "release_date": "2024-02-23",
// "video": false,
// "vote_average": 5.929,
// "vote_count": 70

#include <stdio.h>
#include <stdlib.h>

struct Song {
    int songID;
    char title[100];
    char artist[100];
    float duration; // in minutes
};

void addSong(struct Song playlist[], int *songCount);
void playSong(struct Song playlist[], int songCount);
void displayPlaylist(struct Song playlist[], int songCount);
void savePlaylistToFile(struct Song playlist[], int songCount);
void loadPlaylistFromFile(struct Song playlist[], int *songCount);

int main() {
    const int MAX_SONGS = 100;
    struct Song playlist[MAX_SONGS];
    int songCount = 0;
    int choice;

    // Load playlist from file
    loadPlaylistFromFile(playlist, &songCount);

    do {
        // Display menu
        printf("\nMusic Playlist System\n");
        printf("1. Add Song\n");
        printf("2. Play Song\n");
        printf("3. Display Playlist\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(playlist, &songCount);
                break;
            case 2:
                playSong(playlist, songCount);
                break;
            case 3:
                displayPlaylist(playlist, songCount);
                break;
            case 4:
                // Save playlist to file before exiting
                savePlaylistToFile(playlist, songCount);
                printf("Exiting the Music Playlist System.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void addSong(struct Song playlist[], int *songCount) {
    if (*songCount < 100) {
        printf("Enter song title: ");
        scanf(" %[^\n]", playlist[*songCount].title);
        printf("Enter artist: ");
        scanf(" %[^\n]", playlist[*songCount].artist);
        printf("Enter duration (in minutes): ");
        scanf("%f", &playlist[*songCount].duration);

        playlist[*songCount].songID = *songCount + 1;
        (*songCount)++;

        printf("Song added successfully!\n");
    } else {
        printf("Playlist is full. Cannot add more songs.\n");
    }
}

void playSong(struct Song playlist[], int songCount) {
    if (songCount > 0) {
        printf("Enter the song ID to play: ");
        int songID;
        scanf("%d", &songID);

        if (songID >= 1 && songID <= songCount) {
            printf("Playing Song %d: %s by %s (Duration: %.2f minutes)\n", playlist[songID - 1].songID,
                   playlist[songID - 1].title, playlist[songID - 1].artist, playlist[songID - 1].duration);
        } else {
            printf("Invalid song ID. Please enter a valid ID.\n");
        }
    } else {
        printf("The playlist is empty. Add songs before playing.\n");
    }
}

void displayPlaylist(struct Song playlist[], int songCount) {
    if (songCount > 0) {
        printf("\nPlaylist:\n");
        printf("ID\tTitle\t\t\tArtist\t\t\tDuration\n");
        for (int i = 0; i < songCount; i++) {
            printf("%d\t%-25s%-25s%.2f\n", playlist[i].songID, playlist[i].title, playlist[i].artist,
                   playlist[i].duration);
        }
    } else {
        printf("The playlist is empty. Add songs to display.\n");
    }
}

void savePlaylistToFile(struct Song playlist[], int songCount) {
    FILE *file = fopen("playlist_records.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < songCount; i++) {
            fprintf(file, "%d,%s,%s,%.2f\n", playlist[i].songID, playlist[i].title, playlist[i].artist,
                    playlist[i].duration);
        }
        fclose(file);
        printf("Playlist saved to file successfully.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}

void loadPlaylistFromFile(struct Song playlist[], int *songCount) {
    FILE *file = fopen("playlist_records.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d,%99[^,],%99[^,],%f", &playlist[*songCount].songID, playlist[*songCount].title,
                      playlist[*songCount].artist, &playlist[*songCount].duration) == 4) {
            (*songCount)++;
            if (*songCount >= 100) {
                printf("Warning: Maximum playlist size reached. Some songs may not be loaded.\n");
                break;
            }
        }
        fclose(file);
        printf("Playlist loaded from file.\n");
    } else {
        printf("No playlist file found. Creating a new playlist.\n");
    }
}

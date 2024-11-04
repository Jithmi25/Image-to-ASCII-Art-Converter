# Image to ASCII Art Converter 🎨🖼️

This project allows you to convert grayscale images to ASCII art using C programming! The ASCII art representation captures the image in a text-based format, offering a unique and creative way to view visual content.

## 🚀 Features

- Converts **PGM (P2)** format grayscale images to ASCII art.
- Uses an ASCII character gradient to represent different shades in the image.
- Supports any ASCII-based text editor to display the output.

## 📋 Requirements

- **ImageMagick** for converting images to PGM format.
- A C compiler (e.g., GCC).

## ⚙️ Setup

### 1. Install ImageMagick
- **Linux (Ubuntu/Debian)**: `sudo apt install imagemagick`
- **macOS** (using Homebrew): `brew install imagemagick`
- **Windows**: [Download ImageMagick](https://imagemagick.org/script/download.php#windows)

### 2. Convert an Image to PGM Format
To use an image with this program, convert it to PGM (P2) format:

```bash
magick input_image.jpg -resize 100x50 -colorspace Gray pgm:output_image.pgm
```

## 💡 Notes
- For best results, resize your images to around 100x50 pixels or smaller before conversion.
- Use a plain text editor to view the ASCII art output.


## 🎉 Contributions
- Contributions are welcome! Feel free to submit issues or create pull requests. 😊

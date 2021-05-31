<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' ); /* no password for test */

/** MySQL hostname */
define( 'DB_HOST', 'mariadb' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '0E;[eI=ygx&uf4A1eD?$VrJ%QxYtvPic;6b8X^1T1h2-u+wNkxbfP?n(aW!z89K$');
define('SECURE_AUTH_KEY',  'VGXOW^s{scJ>v~Z(:r$JM`k|#@2DkLza8BD E+{(f8LAWq-v}z?f){-(F9zAkUj1');
define('LOGGED_IN_KEY',    'd0pqhgfPJp6R~GY]ZKMCd?l$5^-F1Qd*v*UPZpB({I|q<e,Nrd]35;{2^`n)$5v)');
define('NONCE_KEY',        'eJpNtKdwvib_R<tZ9S+v3t7]8GVd6f[ a8}t<ffEg#KY+-kf-Xw#2=/WNQ|<fZxN');
define('AUTH_SALT',        'j5Byl+1RTa7RoyU,zFl<U_E<#Ii=CIrJ+0q1nL6|gg-8k,D[}vHx$y8GmDjg3G:y');
define('SECURE_AUTH_SALT', '^-FkS/qUbe%Sv1MfM%rDRn`5M1w2l=$yg6-$Dp]-+MpfBZ:h_J+{-&]GUB4vd#ke');
define('LOGGED_IN_SALT',   'b8EiJ]y)nT0OKcmOQ6XLu,/WwbflC<DS2@m]dtZ J6?da)S|+J|9(ahQc$Fm]U-1');
define('NONCE_SALT',       'vl=thAh`X]<K^rQ{/gNhCrF}(qWN/@_$C|T?yhAEP.f/mc,|?+DC:Dx$M|&UH2;c');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
